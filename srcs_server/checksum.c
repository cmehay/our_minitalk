/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:48:38 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 16:12:15 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	bin_to_char(t_bit *bits)
{
	unsigned char	bin;
	unsigned char	adder;
	int				i;
	int				bit[8];

	bin = 0;
	adder = 1;
	i = -1;
	while (++i < 8)
	{
		bit[i] = bits->bit;
		bits = bits->next;
	}
	while (i--)
	{
		if (bit[i])
			bin += adder;
		adder <<= 1;
	}
	return (bin);
}

static t_str			put_in_str(t_bit *bits)
{
	t_bit			*tmp;
	t_str			rtn;
	unsigned char	*str;

	tmp = bits;
	while (tmp)
		tmp = tmp->next;
	str = (unsigned char*)safe_malloc(sizeof(unsigned char) * (tmp->idx / 8));
	rtn.str = str;
	tmp = bits;
	while (tmp)
	{
		if (tmp->idx > 0 && !(tmp->idx % 8))
		{
			if (!(*str++ = bin_to_char(tmp)))
				break ;
		}
		tmp = tmp->next;
	}
	rtn.crc8 = bin_to_char(tmp->next);
	return (rtn);
}

t_bool					checksum(t_bit *bits, t_stock *stock)
{
	t_str	str;
	t_crc	crc8;
	t_bool	rtn;

	str = put_in_str(bits);
	crc8 = hr_crc32((char*)str.str, ft_strlen((char*)str.str), 0, TRUE);
	if (crc8 == (t_crc)str.crc8)
	{
		ft_putendl((char*)str.str);
		rtn = TRUE;
	}
	else
		rtn = FALSE;
	free(str.str);
	reset_str(bits);
	stock->bit = NULL;
	return (rtn);
}