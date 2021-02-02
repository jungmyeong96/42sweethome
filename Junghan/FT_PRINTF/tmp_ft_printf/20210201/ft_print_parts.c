/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:52:08 by junghan           #+#    #+#             */
/*   Updated: 2021/02/02 00:50:12 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_no_hyphen1(char *hy_zero, char *str, int width, int len)
{
	while(width--)
		write(1, hy_zero, sizeof(char));
	write(1, str, sizeof(char) * len);
}

void	ft_is_hyphen1(char *hy_zero, char *str, int width, int len)
{
	write(1, str, (sizeof(char) * len));
	while (width--)
		write(1, hy_zero, sizeof(char));
}

int		ft_print_char(const char *spec, char *str, t_info info, int len)
{
	int 	width;
	char	*hy_zero;
	int		result;

	hy_zero = " ";
	if (*spec == '%' && info.f_zero == YES && info.f_hyphen == NO)
		hy_zero = "0";
	if (len > info.w_num)
		width = 0;
	else
		width = info.w_num - len;
	result = width + len;
	if (info.f_hyphen == YES)
		ft_is_hyphen1(hy_zero, str, width, len);
	else
		ft_no_hyphen1(hy_zero, str, width, len);
	return (result);
}

void	ft_no_hyphen2(char *str, int width, t_info info, int sign)
{
	char	*hy_zero;
	int		str_len;
	int		prenum;
	int		flag;

	flag = 0;
	str_len = ft_strlen(str);
	prenum = (info.p_num > str_len) ? info.p_num - str_len : 0 ;
	hy_zero = (info.f_zero == YES && (info.p_existence == NODOT ||
				(info.p_num < 0 && prenum <= 0))) ? "0" : " ";
	if (sign < 0 && info.f_zero == YES && width > 0 &&
			(info.p_num < 0 || info.p_existence == NODOT))
	{
		write(1, "-", sizeof(char));
		flag = 1;
	}
	if (width > 0)
		while (width--)
			write(1, hy_zero, sizeof(char));
	if (sign < 0 && flag == 0)
		write(1, "-", sizeof(char));
	while (prenum--)
		write(1, "0", sizeof(char));
	write(1, str, (sizeof(char) * ft_strlen(str)));
}

void	ft_is_hyphen2(char *str, int width, int prenum, int sign)
{
	if (sign < 0)
		write(1, "-", sizeof(char));
	while (prenum--)
		write(1, "0", sizeof(char));
	write(1, str, (sizeof(char) * ft_strlen(str)));
	if (width > 0)
		while (width--)
			write(1, " ", sizeof(char));
}

int		ft_print_int(char *str, t_info info, int sign)
{
	int		str_len;
	int		width;
	int		prenum;
	int		result;

	width = 0;
	str_len = ft_strlen(str);
	prenum = (info.p_num > str_len) ? info.p_num - str_len : 0 ;
	result = prenum + str_len;
	width = (prenum > 0) ?  info.w_num - info.p_num : info.w_num - str_len;
	if (sign < 0)
		width--;
	if (width > 0)
		result += width;
	if (info.f_hyphen == YES)
		ft_is_hyphen2(str, width, prenum, sign);
	else
		ft_no_hyphen2(str, width, info, sign);
	return (result);
}
