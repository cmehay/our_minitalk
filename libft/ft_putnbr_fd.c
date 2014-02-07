/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:10:23 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/17 12:24:42 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int64_t n, int fd)
{
	uint64_t	usgn_copy;
	int64_t		nb_size;
	int64_t		nb_copy;
	int64_t		nb_print;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	usgn_copy = n * ((n > 0) + (n > 0) - 1);
	nb_size = 1;
	nb_copy = usgn_copy;
	while (nb_copy / 10 > 0)
	{
		nb_size *= 10;
		nb_copy /= 10;
	}
	while (nb_size > 0)
	{
		nb_print = 0;
		nb_print = usgn_copy / nb_size;
		ft_putchar_fd(nb_print + '0', fd);
		usgn_copy = usgn_copy % nb_size;
		nb_size = nb_size / 10;
	}
}
