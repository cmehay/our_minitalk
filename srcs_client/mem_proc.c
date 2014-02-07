/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:32:29 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/07 22:37:29 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*safe_malloc(size_t len)
{
	void	*alloc;

	if (!(alloc = ft_memalloc(len)))
		exit_hook(ERR_MALLOC);
	return (alloc);
}
