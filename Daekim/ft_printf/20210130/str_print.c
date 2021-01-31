/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:32 by daekim            #+#    #+#             */
/*   Updated: 2021/01/30 17:20:46 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_c(char c, t_cond *con, int *ret)
{
	int		len;

	if (con->minus == 1 || con->minus_pre == 1)
		write(1, &c, 1);
	if (con->minus_pre == 0)
	{
		len = con->width - 1;
//		if (con->dot == 1 && con->pre == 0)
//			len = con->width - 1;
	}
	else
		len = con->pre - 1;
	while (len-- > 0)
	{
		if (con->zero == 1 && con->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	if (con->minus == 0 && con->minus_pre == 0)
		write(1, &c, 1);
	(*ret)++;
	return (*ret);
}

int			print_morz(t_cond *con, int len, int *ret)
{
	int		f_len;

	if (con->width <= len && con->pre <= len)
		return (*ret);
	if (con->minus_pre == 0)
	{
		f_len = con->width - len;
//		if (con->dot == 1 && con->pre == 0)
//			f_len = con->width;
	}
	else 
		f_len = con->pre;
	while (f_len-- > 0)
	{
		if (con->zero == 1 && con->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	return (*ret);
}

int			print_str(char *str, t_cond *con, int len, int *ret)
{
	int		i;

	i = 0;
	if (con->minus_pre == 1 && con->pre != 0)
	{
		con->dot = 0;
		con->minus_pre = 0;
	}
	if ((con->minus == 1 || con->minus_pre == 1))
		while (i < len)
		{
			if (con->dot == 1 && con->pre == 0)
				break ;
			write(1, &str[i++], 1);
			ret++;
		}
	*ret = print_morz(con, len, ret);
	if (con->minus == 0 && con->minus_pre == 0)	
	{
		if (con->dot == 1 && con->pre == 0)
			return (*ret);
		while (i < len)
		{
			write(1, &str[i++], 1);
			(*ret)++;
		}
	}
	return (*ret);
}

int			print_num_morz(t_cond *con, int len, int *ret)
{
	int		f_len;

	if (con->width <= len && con->pre <= len)
		return (*ret);
	if (con->width > con->pre && con->minus_pre == 0)
		f_len = con->width - len;
	else
		f_len = con->pre - len;
	while (f_len-- > 0)
	{
		if (con->zero == 1 && con->dot == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	return (*ret);
}

int			print_num(char *str, t_cond *con, int len, int *ret)
{
	int		i;

	i = 0;
	if (con->minus == 1 || con->minus_pre == 1)
		while (i < len)
		{
			write(1, &str[i++], 1);
			(*ret)++;
		}
	*ret = print_num_morz(con, len, ret);
	if (con->minus == 0 && con->minus_pre == 0)
		while (i < len)
		{
			write(1, &str[i++], 1);
			(*ret)++;
		}
	return (*ret);
}
