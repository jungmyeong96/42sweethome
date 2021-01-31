/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:00:03 by daekim            #+#    #+#             */
/*   Updated: 2021/01/30 16:28:12 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_cond
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			pre;
	int			p_star;
	int			minus_pre;
}				t_cond;

int				ft_printf(const char *str, ...);
int				type_lst(int c);
int				flag_lst(int c);
int				put_chr(va_list ap, t_cond *con);
int				put_str(va_list ap, t_cond *con);
int				put_poi(va_list ap, t_cond *con);
int				ft_hexlen(size_t n);
char			*ten_hex(size_t n, t_cond *con);
int				put_dig(va_list ap, t_cond *con);
int				ft_tenlen(ssize_t n);
char			*ten_ten(ssize_t n, t_cond *con);
int				put_uni(va_list ap, t_cond *con);
int				put_hex(va_list ap, char c, t_cond *con);
int				put_per(char c, t_cond *con);
void			ft_struct(t_cond *con);
void			ft_opt(const char *str, va_list ap, int *i, t_cond *con);
void			opt_width(const char *str, va_list ap, int *i, t_cond *con);
void			opt_pre(const char *str, va_list ap, int *i, t_cond *con);
int				print_str(char *str, t_cond *con, int len, int *ret);
int				print_num(char *str, t_cond *con, int len, int *ret);
int				print_c(char c, t_cond *con, int *ret);

#endif
