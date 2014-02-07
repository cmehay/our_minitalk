/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:27:25 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/26 08:30:08 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	i = 0;
	if ((rtn = ft_strnew(len)) != NULL)
	{
		while (i < len)
		{
			rtn[i] = s[i + start];
			i++;
		}
	}
	return (rtn);
}
