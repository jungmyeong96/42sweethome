/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:00:03 by daekim            #+#    #+#             */
/*   Updated: 2021/01/27 20:15:16 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

struct	s_con
{
	int	minus;
	int	zero;
	int width;
	int	dot;
	int	type;	
}	t_con;

int		type_lst(int c);
int		flag_lst(int c);
int		put_chr(va_list ap);
int		put_str(va_list ap);
int		put_poi(va_list ap);

#endif
