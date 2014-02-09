/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:36:23 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 16:17:58 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	exit_hook(char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(1);
}
