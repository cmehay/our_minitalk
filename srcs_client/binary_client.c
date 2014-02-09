/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 20:45:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 21:33:11 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reverse(int *bin, int size)
{
	int	*tmp;
	int	i;

	tmp = (int*)safe_malloc(sizeof(int) * size);
	i = size;
	while (size--)
		*tmp++ = bin[size];
	while (i--)
		bin[i] = *(--tmp);
	free(tmp);
}
