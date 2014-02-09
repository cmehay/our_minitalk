/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:42:19 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 11:54:41 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	cb_sigusr(int sig)
{
	t_bool	set;

	if (sig == SIGUSR1)
		set = FALSE;
	if (sig == SIGUSR2)
		set = TRUE;
	gimme_status(&set);
}