/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:40:45 by daekim            #+#    #+#             */
/*   Updated: 2021/01/27 20:00:25 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_div(va_list ap, char c)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret += put_chr(ap);
	else if (c == 's')
		ret += put_str(ap);
	else if (c == 'p')
		ret += put_poi(ap);
/*	else if (c == 'd')
		put_dig(str, ap, &i, c);
	else if (c == 'i')
		put_sii(str, ap, &i, c);
	else if (c == 'u')
		put_uni(str, ap, &i, c);
	else if (c == 'x' || c == 'X')
		put_hex(str, ap, &i, c);
	else if (c == '%')
		put_per(str, ap, &i, c);*/
	return (ret);
}

int			check_cond(const char *str, va_list ap, int *i)
{
	int		idx;
	int		ret;

	idx = *i;
	ret = 0;
	while (str[++idx])
	{
//		if (str[idx] == '0' || str[idx] = '-')
//			ret += check_flag(str, ap, &idx);
//		if (str[idx] > '0' && str[idx] <= '9')
//			ret +=check_width(str, ap, &idx);
//		if (str[idx] == '.')
//			ret += check_pre(str, ap, &idx);
		if (str[idx])
		{
			ret += ft_div(ap, str[idx]);
			break;
		}
		idx++;
	}
	*i = idx;
	return (ret);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			write(1, &str[i++], 1);
			ret++;
		}
		if (str[i] == 0)
			return (ret);
		if (str[i] == '%')
			ret += check_cond(str, ap, &i);
		i++;
	}
	va_end(ap);
	return (ret);
}

int	main()
{
	char c;
	char *s;
	int ret;

	c = '0';
	s = "please";
	ret = ft_printf("test char : %s, %c, %p", s, c, s);
	printf("\n%d\n", ret);
	return (0);
}
