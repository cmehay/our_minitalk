/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:37:23 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/07 23:51:18 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	add_checksum(int *array, int len)
{
	int	i;
	int	j;
	int	check;

	i = -1;
	while (i++ < 7)
	{
		check = 0;
		j = -1;
		while (++j < len)
			check ^= array[j * i];
		array[i * (j + 1)] = check;
	}
}

static int	*to_signal(char *str, int len)
{
	int	rtn;
	int	i;
	int	j;

	rtn = (int*)safe_malloc(sizeof(int) * (len + 2) * 7);
	j = -1;
	while (str[j++])
	{
		i = -1;
		while (++i < 7)
		{
			str[j] >>= 1;
			output[i] = (str[j] & 1);
		}
	}
	add_checksum(rtn, len;
	return (rtn);
}

static void	send_to_server(pid_t pid, char str)
{
	int	*signals;
	int	i;
	int len;

	len = ft_strlen(str);
	signals = to_signal(str, len);
	i = -1;
	while (++i < len + 2)
	{
		
	}

}

int			main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || !(pid = ft_atoi(argv[1]))
		exit_hook(ERR_USAGE);
	if (!kill(pid, 0))
		exit_hook(ERR_SERVER);
	send_to_server(pid, argv[2]);
	return (0);
}
