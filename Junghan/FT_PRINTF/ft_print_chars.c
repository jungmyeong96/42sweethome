/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:53:36 by junghan           #+#    #+#             */
/*   Updated: 2021/02/02 15:43:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_hyphen1(char *hy_zero, char *str, int width, size_t len)
{
	while (width--)
		write(1, hy_zero, sizeof(char));
	write(1, str, sizeof(char) * len);
}

void	ft_is_hyphen1(char *hy_zero, char *str, int width, size_t len)
{
	write(1, str, (sizeof(char) * len));
	while (width--)
		write(1, hy_zero, sizeof(char));
}

int		ft_print_char(const char *spec, char *str, t_info info, size_t len)
{
	int		width;
	char	*hy_zero;
	int		result;

	hy_zero = " ";
	if (*spec == '%' && info.f_zero == YES && info.f_hyphen == NO)
		hy_zero = "0";
	if ((int)len > info.w_num)
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
