/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:02:48 by junghan           #+#    #+#             */
/*   Updated: 2021/01/27 18:01:45 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_info {
	int f_hyphen;
	int f_zero;
	int w_num;
	int p_num;
}	t_info;

int ft_printf(const char *format, ...);
int	ft_parse_arg(va_list ap, const char *format);
void	ft_init_info(t_info *info);
char	*ft_check_info(va_list ap, const char *spec,t_info *info);
char	*ft_manage_spec(va_list ap, const char *spec, t_info info);

#endif
