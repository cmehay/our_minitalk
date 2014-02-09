/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 20:45:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 15:58:39 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stock	*gimme_stock(pid_t pid)
{
	static t_stock	*stock = NULL;
	t_stock			*tmp;

	if (!stock)
	{
		stock = (t_stock*)safe_malloc(sizeof(t_stock));
		stock->pid = pid;
		return (stock);
	}
	tmp = stock;
	while (tmp->next && tmp->pid != pid)
		tmp = tmp->next;
	if (tmp->pid == pid)
		return (tmp);
	tmp->next = (t_stock*)safe_malloc(sizeof(t_stock));
	tmp->next->pid = pid;
	return (tmp->next);
}

void	reset_str(t_bit *bits)
{
	if (bits->next)
		reset_str(bits->next);
	free(bits);
}