/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:46:16 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/09 20:55:41 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

# include "../libft/libft.h"

# define ERR_USAGE "Please, doing it right... client [pid] [string]"
# define ERR_SERVER "Server is not running"
# define ERR_MALLOC "Can't malloc :c"

# define POLY 0xedb88320
# define REDUCE 8

typedef struct	s_bit
{
	int				idx;
	t_bool			bit;
	struct s_bit	*next;
}				t_bit;

typedef struct	s_stock
{
	pid_t			pid;
	t_bit			*bit;
	struct s_stock	*next;
}				t_stock;

typedef struct	s_str
{
	unsigned char	crc8;
	unsigned char	*str;
}				t_str;

typedef uint32_t			t_hash;
typedef uint32_t			t_crc;
typedef struct sigaction	t_sigaction;
/*
** crc32.c
*/
void	hr_crc_init_32(t_crc *table);
t_hash	hr_crc32(const char *str, int size, int shift, t_bool reduce);

/*
** mem_proc.c
*/
void	*safe_malloc(size_t len);

/*
** Client
*/

/*
** exit.c
*/
int		exit_hook(char *msg);

/*
** signals.c
*/
void	cb_sigusr(int sig);

/*
** singleton.c
*/
t_bool	gimme_status(t_bool *status);

/*
** binary_client
*/
void	reverse(int *bin, int size);

/*
** Serveur
*/

/*
** checksum.c
*/
t_bool	checksum(t_bit *bits, t_stock *stock);

/*
** singleton.c
*/
t_stock	*gimme_stock(pid_t pid);
void	reset_str(t_bit *bits);

/*
** signals.c
*/
void	cb_sigusr_server(int sig, siginfo_t *siginfo, void *context);

#endif
