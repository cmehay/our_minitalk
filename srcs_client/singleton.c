/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 20:45:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/08 21:43:43 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bool	gimme_status(t_bool *status)
{
	static t_bool	*cur = NULL;
	t_bools			rtn;

	if (!cur)
		cur = (int*)safe_malloc(sizeof(int));
	if (status)
	{
		*cur = *status;
		rtn = *cur;
	}
	if (!status)
	{
		rtn = *cur;
		*cur = 0;
	}
	return (rtn);
}