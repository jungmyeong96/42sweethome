/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_spec2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:13:23 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 14:50:02 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x_hyphen(char *str, int width, int prenum, t_info info)
{
	char			*hy_zero;
	int				str_len;

	str_len = ft_strlen(str);
	if (info.f_hyphen == NO)
	{
		if (info.f_zero == YES && info.p_existence == NODOT)
			hy_zero = "0";
		else
			hy_zero = " ";
		if (width > 0)
			while (width--)
				write(1, hy_zero, sizeof(char));
		while (prenum--)
			write(1, "0", sizeof(char));
		write(1, str, (sizeof(char) * str_len));
	}
}

void	ft_print_o_hyphen(char *str, t_info info)
{
	int				str_len;
	int				width;
	int				prenum;

	prenum = 0;
	width = 0;
	str_len = ft_strlen(str);
	if (info.p_num > str_len)
		prenum = info.p_num - str_len;
	if (prenum > 0)
		width = info.w_num - info.p_num;
	else
		width = info.w_num - str_len;
	if (info.f_hyphen == YES)
	{
		while (prenum--)
			write(1, "0", sizeof(char));
		write(1, str, (sizeof(char) * str_len));
		if (width > 0)
			while (width--)
				write(1, " ", sizeof(char));
	}
	ft_print_x_hyphen(str, width, prenum, info);
}

int		ft_apply_to_int(va_list *ap, t_info info)
{
	char			*int_str;
	int				num;

	num = va_arg(*ap, int);
	if (!(int_str = ft_itoa(num)))
		return (0);
	if (info.p_num < 0)
		return (0);
	if (num == 0 && ((info.p_existence == DOTNUM && info.p_num == 0)
				|| info.p_existence == NODOT))
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_print_o_hyphen(int_str, info);
	return (1);
}

int		ft_apply_to_unint(va_list *ap, t_info info)
{
	char			*int_str;
	unsigned int	un_num;

	un_num = va_arg(*ap, unsigned int);
	if (!(int_str = ft_itoa(un_num)))
		return (0);
	if (info.p_num < 0)
		return (0);
	if (un_num == 0 && ((info.p_existence == DOTNUM && info.p_num == 0)
			|| info.p_existence == NODOT))
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_print_o_hyphen(int_str, info);
	free(int_str);
	int_str = 0;
	return (1);
}

int		ft_apply_to_hex(va_list *ap, const char *spec, t_info info)
{
	char			*hex_str;
	unsigned int	to_hex;

	to_hex = va_arg(*ap, unsigned int);
	if (!(hex_str = ft_chg_to_hex(to_hex, spec)))
		return (0);
	if (info.p_num < 0)
		return (0);
	if (to_hex == 0 && ((info.p_existence == DOTNUM && info.p_num == 0)
				|| info.p_existence == NODOT))
	{
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	ft_print_o_hyphen(hex_str, info);
	free(hex_str);
	hex_str = 0;
	return (1);
}
