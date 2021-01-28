/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:00:03 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 17:09:49 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_con
{
	int			minus;
	int			zero;
	int			 width;
	int			dot;
	int			 igwit;
	int			pre;
	int			type;	
}				t_con;

int				type_lst(int c);
int				flag_lst(int c);
int				put_chr(va_list ap);
int				put_str(va_list ap);
int				put_poi(va_list ap);
int				ft_hexlen(size_t n);
char			*ten_hex(size_t n);
int				put_dig(va_list ap);
int				ft_tenlen(ssize_t n);
char			*ten_ten(ssize_t n);
int				put_uni(va_list ap);
int				put_hex(va_list ap, char c);
int				put_per(char c);

#endif
