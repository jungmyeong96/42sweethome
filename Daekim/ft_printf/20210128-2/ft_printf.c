/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:40:45 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 23:17:03 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_struct(t_cond *con)
{
	con->minus = 0;
	con->zero = 0;
	con->width = 0;
	con->dot = 0;
	con->pre = 0;
}

int			ft_div(va_list ap, char c, t_cond *con)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret += put_chr(ap, con);
	else if (c == 's')
		ret += put_str(ap, con);
	else if (c == 'p')
		ret += put_poi(ap, con);
	else if (c == 'd' || c == 'i')
		ret += put_dig(ap, con);
	else if (c == 'u')
		ret += put_uni(ap, con);
	else if (c == 'x' || c == 'X')
		ret += put_hex(ap, c, con);
	else if (c == '%')
		ret += put_per('%', con);
	return (ret);
}

int			check_cond(const char *str, va_list ap, int *i)
{
	int		idx;
	int		ret;
	t_cond	con;

	idx = *i;
	ret = 0;
	while (str[++idx])
	{
		ft_struct(&con);
		ft_opt(str, ap, &idx, &con);
		if (str[idx])
		{
			ret += ft_div(ap, str[idx], &con);
			break ;
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
//	char c;
//	char *s;
//	int ret;
//	unsigned int un1;
//	unsigned int un2;
//	int t;

//	c = '0';
//	s = "please";
//	un1 = 4294967295;
//	un2 = 0;
//	t = 12345;
	ft_printf("[%010.3d]\n", 12345);
	printf("[%010.3d]\n", 12345);
	ft_printf("[%010d]\n", 12345);
	printf("[%010d]\n", 12345);
	ft_printf("[%-10.7d]\n", 12345);
	printf("[%-10.7d]\n", 12345);
	ft_printf("[%-7.3d]\n", 12345);
	printf("[%-7.3d]\n", 12345);
	ft_printf("[%-.3s]\n", "12345");
	printf("[%-.3s]\n", "12345");
	ft_printf("[%-4.3s]\n", "12345");
	printf("[%-4.3s]\n", "12345");
	ft_printf("[%-3.6s]\n", "12345");
	printf("[%-3.6s]\n", "12345");
	ft_printf("[%-7.6s]\n", "12345");
	printf("[%-7.6s]\n", "12345");
	ft_printf("[%-010.5%]\n");
	printf("[%-010.5%]\n");

//	printf("\n%d\n", ret);
	return (0);
}
