/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 20:45:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 16:18:03 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bool	gimme_status(t_bool *status)
{
	static t_bool	*cur = NULL;
	t_bool			rtn;

	if (!cur)
		cur = (t_bool*)safe_malloc(sizeof(t_bool));
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