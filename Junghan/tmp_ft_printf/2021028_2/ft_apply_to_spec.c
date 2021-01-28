/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:10:07 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 23:53:16 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printwidth(const char *spec, char *str, t_info info)
{
	int len;
	int width;
	char *hy_zero;

	hy_zero = " ";
	if (*spec == '%' && info.f_zero == 1 && info.f_hyphen == 0)
		hy_zero = "0";
	//if (*spec == 'p') ????
	len = ft_strlen(str);
	if (len > info.w_num)
		width = len - info.w_num;
	else
		width = info_w_num - len;
	if (info.f_hyphen == 1)
	{
		write(1, str, (sizeof(char) * len));
		while(width--)
			write(1, hy_zero, sizeof(char));
	}
	else
	{
		while(width--)
			write(1, hy_zero, sizeof(char));
		write(1, str, (sizeof(char) * len));
	}
}

int	ft_apply_to_percent(va_list ap, const char *spec, t_info info)
{
	char percent;

	percent = va_arg(ap, int);
	if (info.p_num < 0)
		return (0);
	ft_printwidth(spec, &percent, info);
	return (1);
}
int	ft_apply_to_char(va_list ap, const char *spec, t_info info)
{
	char c;

	c = va_arg(ap, int);
	if ((info.p_existence == 1) || (info.f_zero == 1))
		return (0);
	ft_printwidth(spec, &c, info);
	return (1);
}

int	ft_apply_to_str(va_list ap, const char *spec, t_info info)
{
	char *str;

	str = va_arg(ap, char *);
	if (info.f_zero == 1 || (info.p_existence = 1 && info.p_num < 0))
		return (0);
	if ((info.p_existence == 1 && info.p_num == 0) || info.p_existence == 2)
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_printwidth(spec, str, info);
	return (1);
}

void	ft_apply_to_pointer(va_list ap, const char *spec, t_info info)
{
	void			*ptr;
	char			*hex_ptr;
	unsigned int	to_hex;

	ptr = va_arg(ap, void *);
	if ((info.p_existence == 1) || (info.f_zero == 1))
		return (0);
	write(1, "0x", (sizeof(char) * 2));
	to_hex = (unsigned int)ptr;
	hex_ptr = ft_chg_to_hex(to_hex, spec);
	ft_printwidth(spec, hex_ptr, info);
	return (1);
}
