/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:46:16 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/07 22:35:51 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>

# define ERR_USAGE "Please, doing it right... client [pid] [string]"
# define ERR_SERVER "Server is not running"

typedef struct	s_str
{
	char			c;
	struct s_str	*next;
}				t_str;

typedef struct	s_stock
{
	pid_t			pid;
	t_str			*str;
	struct s_stock	*next;
}				t_stock;

#endif