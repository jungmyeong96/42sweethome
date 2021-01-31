/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:10:07 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 17:54:24 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_spec(const char *spec, char *str, t_info info, int len)
{
	int				width;
	char			*hy_zero;
	int				result;

	hy_zero = " ";
	if (*spec == '%' && info.f_zero == YES && info.f_hyphen == NO)
		hy_zero = "0";
	if (len > info.w_num)
		width = 0;
	else
		width = info.w_num - len;
	result = width + len;
	if (info.f_hyphen == YES)
	{
		write(1, str, (sizeof(char) * len));
		while (width--)
			write(1, hy_zero, sizeof(char));
	}
	else
	{
		while (width--)
			write(1, hy_zero, sizeof(char));
		write(1, str, (sizeof(char) * len));
	}
	return (result);
}

int		ft_apply_to_percent(const char *spec, t_info info, int *result)
{
	int				len;

	if (info.p_num < 0)
		return (0);
	len = 1;
	*result += ft_print_spec(spec, "%", info, len);
	return (1);
}

int		ft_apply_to_char(va_list *ap, const char *spec, t_info info, int *result)
{
	char			c;
	int				len;

	c = va_arg(*ap, int);
	if ((info.p_existence == DOTNUM) || (info.f_zero == YES))
		return (0);
	len = 1;
	*result += ft_print_spec(spec, &c, info, len);
	return (1);
}

int		ft_apply_to_str(va_list *ap, const char *spec, t_info info, int *result)
{
	char			*str;
	int				len;

	if ((str = va_arg(*ap, char *)) == NULL)
		str = "(null)";
	if (info.f_zero == YES || (info.p_existence == DOTNUM && info.p_num < 0
				&& info.p_asterisk == NO))
		return (0);
	if ((info.p_existence == DOTNUM && info.p_num == 0)
			|| info.p_existence == ONLYDOT)
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	len = ft_strlen(str);
	if (info.p_existence == DOTNUM && info.p_num > 0 && info.p_num < len)
		len = info.p_num;
	*result += ft_print_spec(spec, str, info, len);
	return (1);
}

int		ft_apply_to_pointer(va_list *ap, const char *spec, t_info info, int *result)
{
	void			*ptr;
	char			*hex_ptr;
	unsigned int	to_hex;
	int				len;

	ptr = va_arg(*ap, void *);
	if ((info.p_existence == DOTNUM) || (info.f_zero == YES))
		return (0);
	write(1, "0x", (sizeof(char) * 2));
	to_hex = (unsigned int)ptr;
	if (!(hex_ptr = ft_chg_to_hex(to_hex, spec)))
		return (0);
	len = ft_strlen(hex_ptr);
	*result += ft_print_spec(spec, hex_ptr, info, len);
	free(hex_ptr);
	hex_ptr = 0;
	return (1);
}
