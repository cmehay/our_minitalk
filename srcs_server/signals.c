/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 11:31:47 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 23:16:21 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		check_it(t_bit *tmp, int *cnt0, int *cnt1, int *idx)
{
		while (tmp)
	{
		if (!tmp->bit)
			(*cnt0)++;
		else
		{
			*cnt0 = (*cnt0 >= 15) ? 16 : 0;
			*cnt1 = (*cnt0 == 16) ? (*cnt1) + 1 : 0;
		}
		*idx = tmp->idx;
		tmp = tmp->next;
	}
}

static t_bool	check_input(t_bit *bits, t_stock *stock)
{
	t_bit	*tmp;
	int		idx;
	int		cnt0;
	int		cnt1;

	tmp = bits;
	cnt0 = 0;
	cnt1 = 0;
	check_it(tmp, &cnt0, &cnt1, &idx);
	if (cnt0 == 16 && cnt1 == 8 && !((idx + 1) % 8))
		return (checksum(bits, stock));
	if (cnt0 == 16 && cnt1 == 8 && ((idx + 1) % 8))
	{
		reset_str(bits);
		stock->bit = NULL;
	}
	return (FALSE);
}

static t_bool	add_bit(pid_t pid, t_bool bit)
{
	t_stock	*stock;
	t_bit	*bits;
	int		idx;

	stock = gimme_stock(pid);
	idx = 1;
	if (!stock->bit)
	{
		stock->bit = (t_bit*)safe_malloc(sizeof(t_bit));
		stock->bit->bit = bit;
		stock->bit->idx = 0;
		return (TRUE);
	}
	bits = stock->bit;
	while (bits->next)
	{
		idx++;
		bits = bits->next;
	}
	bits->next = (t_bit*)safe_malloc(sizeof(t_bit));
	bits->next->bit = bit;
	bits->next->idx = idx;
	return (check_input(stock->bit, stock));
}

static void		send_signal(pid_t pid, t_bool sig)
{
	if (sig)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

void			cb_sigusr_server(int sig, siginfo_t *siginfo, void *context)
{
	t_bool	set;

	(void)context;
	if (sig == SIGUSR1)
		set = FALSE;
	if (sig == SIGUSR2)
		set = TRUE;
	if (siginfo->si_pid)
		send_signal(siginfo->si_pid, add_bit(siginfo->si_pid, set));
}
