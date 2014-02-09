/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:38:23 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 16:21:56 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void add_begin_end(int *array, int len, t_bool begin)
{
	int		i;
	int		shift;
	i = -1;

	shift = (begin) ? 0 : (len + 5) * 8;
	while (++i < 8)
		array[i + shift] = 1;
}

static void	add_checksum(int *array, char *str, int len)
{
	t_crc	crc8;
	int		i;

	crc8 = hr_crc32(str, len, 0, TRUE);
	i = -1;
	while (++i < 8)
	{
		crc8 >>= 1;
		array[i + (len + 2) * 8] = (crc8 & 1);
	}
}

static int	*to_signal(char *str, int len)
{
	int	*rtn;
	int	i;
	int	j;

	rtn = (int*)safe_malloc(sizeof(int) * (len + 6) * 8);
	j = -1;
	add_begin_end(rtn, len, TRUE);
	while (str[j++])
	{
		i = -1;
		while (++i < 8)
		{
			str[j] >>= 1;
			rtn[i + (j + 1) * 8] = (str[j] & 1);
		}
	}
	add_checksum(rtn, str, len);
	add_begin_end(rtn, len, FALSE);
	return (rtn);
}

static void	send_to_server(pid_t pid, char *str, int *sig)
{
	int	*signals;
	int	i;
	int len;

	len = ft_strlen(str);
	signals = (sig) ? sig : to_signal(str, len);
	i = -1;
	while (++i < (len + 5) * 8)
	{
		if (signals[i])
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_hook(ERR_SERVER);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_hook(ERR_SERVER);
		}
		pause();
	}
	if (!gimme_status(NULL))
		send_to_server(pid, str, signals);
}

int			main(int argc, char **argv)
{
	pid_t	pid;

	signal(SIGUSR1, cb_sigusr);
	signal(SIGUSR2, cb_sigusr);
	if (argc != 3 || !(pid = ft_atoi(argv[1])))
		exit_hook(ERR_USAGE);
	if (kill(pid, 0) == -1)
		exit_hook(ERR_SERVER);
	send_to_server(pid, argv[2], NULL);
	return (0);
}
