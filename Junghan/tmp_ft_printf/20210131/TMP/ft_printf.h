/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:02:48 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 17:50:18 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define ONLYDOT 2
# define DOTNUM 1
# define NODOT 0
# define YES 1
# define NO 0

typedef struct	s_info
{
	int			f_hyphen;
	int			f_zero;
	int			w_num;
	int			p_num;
	int			p_existence;
	int			p_asterisk;
}				t_info;

int				ft_printf(const char *format, ...);
int				ft_parse_arg(va_list *ap, const char *format);
void			ft_init_info(t_info *info);
char			*ft_check_info(va_list *ap, const char *spec, t_info *info);
const char		*ft_manage_spec(va_list *ap, const char *spec, t_info info, int *result);
int				ft_apply_to_percent(const char *spec, t_info info, int *result);
int				ft_apply_to_char(va_list *ap, const char *spec, t_info info, int *result);
int				ft_apply_to_str(va_list *ap, const char *spec, t_info info, int *result);
int				ft_apply_to_pointer(va_list *ap, const char *spec, t_info info, int *result);
int				ft_apply_to_int(va_list *ap, t_info info, int *result);
int				ft_apply_to_unint(va_list *ap, t_info info, int *result);
int				ft_apply_to_hex(va_list *ap, const char *spec, t_info info, int *result);
char			*ft_chg_to_hex(unsigned int num, const char *spec);

#endif
