/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:37:23 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/08 21:54:59 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	add_checksum(int *array, char *str, int len)
{
	t_crc	crc7;
	int		i;

	crc7 = hr_crc32(str, len, 0, TRUE);
	i = -1;
	while (++i < 7)
	{
		crc7 >>= 1;
		array[i + (len + 3) * 7] = (crc7 & 1);
	}
}

static int	*to_signal(char *str, int len)
{
	int	rtn;
	int	i;
	int	j;

	rtn = (int*)safe_malloc(sizeof(int) * (len + 5) * 7);
	j = -1;
	while (str[j++])
	{
		i = -1;
		while (++i < 7)
		{
			str[j] >>= 1;
			rtn[i + (j * 7)] = (str[j] & 1);
		}
	}
	add_checksum(rtn, str, len);
	return (rtn);
}

static void	send_to_server(pid_t pid, char str, int *sig)
{
	int	*signals;
	int	i;
	int len;

	len = ft_strlen(str);
	signals = (sig) ? sig : to_signal(str, len);
	i = -1;
	while (++i < (len + 5) * 7)
	{
		if (signals[i])
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
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
	if (argc != 3 || !(pid = ft_atoi(argv[1]))
		exit_hook(ERR_USAGE);
	if (!kill(pid, 0))
		exit_hook(ERR_SERVER);
	send_to_server(pid, argv[2], NULL);
	return (0);
}
