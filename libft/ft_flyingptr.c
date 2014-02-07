/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flyingptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:34:00 by cmehay            #+#    #+#             */
/*   Updated: 2014/01/09 16:16:07 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function backups ptr somewhere in the code and retrieves
** it somewhere else.
*/
void	*ft_flyingptr(int idx, void *data)
{
	static t_fly	backup[256] =
	{
		{
			NULL
		}
	};

	if (data)
		backup[idx].data = data;
	return (backup[idx].data);
}