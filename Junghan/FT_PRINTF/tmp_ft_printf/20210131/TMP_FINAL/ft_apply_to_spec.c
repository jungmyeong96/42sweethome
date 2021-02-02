/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:10:07 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 15:04:32 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printwidth(const char *spec, char *str, t_info info, int len)
{
	int				width;
	char			*hy_zero;

	hy_zero = " ";
	if (*spec == '%' && info.f_zero == YES && info.f_hyphen == NO)
		hy_zero = "0";
	if (len > info.w_num)
		width = 0;
	else
		width = info.w_num - len;
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
}

int		ft_apply_to_percent(const char *spec, t_info info)
{
	int				len;

	if (info.p_num < 0)
		return (0);
	len = 1;
	ft_printwidth(spec, "%", info, len);
	return (1);
}

int		ft_apply_to_char(va_list *ap, const char *spec, t_info info)
{
	char			c;
	int				len;

	c = va_arg(*ap, int);
	if ((info.p_existence == DOTNUM) || (info.f_zero == YES))
		return (0);
	len = 1;
	ft_printwidth(spec, &c, info, len);
	return (1);
}

int		ft_apply_to_str(va_list *ap, const char *spec, t_info info)
{
	char			*str;
	int				len;

	if ((str = va_arg(*ap, char *)) == NULL)
		str = "(NULL)";
	if (info.f_zero == YES || (info.p_existence = DOTNUM && info.p_num < 0))
		return (0);
	if ((info.p_existence == DOTNUM && info.p_num == 0)
			|| info.p_existence == ONLYDOT)
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	len = ft_strlen(str);
	ft_printwidth(spec, str, info, len);
	return (1);
}

int		ft_apply_to_pointer(va_list *ap, const char *spec, t_info info)
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
	ft_printwidth(spec, hex_ptr, info, len);
	free(hex_ptr);
	hex_ptr = 0;
	return (1);
}
