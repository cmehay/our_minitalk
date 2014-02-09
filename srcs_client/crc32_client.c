/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc32_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 04:40:57 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 16:17:59 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		hr_crc_init_32(t_crc *table)
{
	t_crc		rem;
	int			div;
	uint8_t		bit;

	div = 0;
	while (div < 256)
	{
		rem = div;
		bit = 8;
		while (bit-- > 0)
			rem = (rem & 1) ? (rem >> 1) ^ POLY : (rem >> 1);
		table[div++] = rem;
	}
}

t_hash		hr_crc32(const char *str, int size, int shift, t_bool reduce)
{
	static t_bool	flag = FALSE;
	const char		*tmp;
	static t_crc	table[256];
	t_crc			crc;

	reduce = (REDUCE < 32) ? reduce : FALSE;
	if (!flag)
	{
		hr_crc_init_32(table);
		flag = TRUE;
	}
	crc = 0 ^ ~0U;
	tmp = str;
	while (size--)
		crc = table[(crc ^ (*tmp++ << shift)) & 0xFF] ^ (crc >> 8);
	if (reduce)
		return ((crc ^ ~0U) & ((1 << REDUCE) - 1));
	return (crc ^ ~0U);
}