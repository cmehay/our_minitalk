/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:44:17 by cmehay            #+#    #+#             */
/*   Updated: 2014/01/18 19:05:27 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_str(char const *s1, int s2_len, char const *str)
{
	int		s1_len;
	int		str_len;
	int		i;
	char	*str_srch;

	i = 0;
	str_srch = (char*)str;
	s1_len = ft_strlen(s1);
	str_len = ft_strlen(str);
	while (*str_srch && (str_srch = ft_strstr(str_srch, s1)))
	{
		i++;
		str_srch += s1_len;
	}
	return (ft_strnew(str_len + ((s2_len - s1_len) * i)));
}

char		*ft_strrep(char const *s1, char const *s2, char const *str)
{
	char	*rtn;
	char	*str_srch;
	int		i;
	int		shift_1;
	int		shift_2;

	shift_1 = ft_strlen(s1);
	shift_2 = ft_strlen(s2);
	if (!(rtn = new_str(s1, ft_strlen(s2), str)))
		return (NULL);
	ft_strcpy(rtn, str);
	i = 0;
	str_srch = (char*)str;
	while (*str_srch && (str_srch = ft_strstr(str_srch, s1)))
	{
		if (!str_srch)
			str_srch = (char*)str + ft_strlen(str);
		ft_strcpy(rtn + (str_srch - str) + ((shift_2 - shift_1) * i), s2);
		str_srch += shift_1;
		i++;
		ft_strcpy(rtn + (str_srch - str) + ((shift_2 - shift_1) * i), str_srch);
	}
	return (rtn);
}
