/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:40:45 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 18:02:36 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void		ft_struct(t_con cond)
{
	cond->minus = 0;
	cond->zero = 0;
	cond->width = 0;
	cond->dot = 0;
	cond->igwid = 0;
	cond->pre = 0;
	cond->type = 0;
}*/

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
	else if (c == 'd' || c == 'i')
		ret += put_dig(ap);
	else if (c == 'u')
		ret += put_uni(ap);
	else if (c == 'x' || c == 'X')
		ret += put_hex(ap, c);
	else if (c == '%')
		ret += put_per('%');
	return (ret);
}

int			check_cond(const char *str, va_list ap, int *i)
{
//	int		idx;
	int		ret;

//	idx = *i;
	ret = 0;
	while (str[(*i)++])
	{
//		if (str[idx] == '0' || str[idx] = '-')
//			ret += check_flag(str, ap, &idx);
//		if (str[idx] > '0' && str[idx] <= '9')
//			ret +=check_width(str, ap, &idx);
//		if (str[idx] == '.')
//			ret += check_pre(str, ap, &idx);
//		ft_opt(str, ap, &idx);
		if (str[*i])
		{
			ret += ft_div(ap, str[*i]);
			break;
		}
		++*i;
	}
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
	unsigned int un1;
//	unsigned int un2;

	c = '0';
	s = "please";
	un1 = 4294967295;
//	un2 = 0;
	ret = ft_printf("test char : %s, %c, %p, %%, %x, %X\n", s, c, s, un1, un1);
	printf("test char : %s, %c, %p, %%, %x, %X", s, c, s, un1, un1);
	printf("\n%d\n", ret);
	return (0);
}
