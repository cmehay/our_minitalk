/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:38:15 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 17:55:43 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		main(void)
{
	pid_t		pid;
	t_sigaction	act;

	act.sa_sigaction = cb_sigusr_server;
	act.sa_flags |= SA_SIGINFO;
	act.sa_flags &= ~SA_RESETHAND;
	pid = getpid();
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr("Pid: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	ft_putendl("Server is running...");
	while (1)
		pause();
	ft_putendl("exit");
	return (0);
}
