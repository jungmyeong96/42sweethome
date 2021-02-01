/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:32 by daekim            #+#    #+#             */
/*   Updated: 2021/02/01 20:57:11 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_poi(char *str, t_cond *con, int len, int *ret)
{
	int		i;
	int		f_len;

	i = 0;
	if (con->p_star == 1 && con->width < con->pre)
	{
		con->minus_pre = 0;
		con->pre = con->width;
	}
	if (con->minus == 1 || con->minus_pre == 1)
		while (str[i])
			{
				if (con->dot == 1 && con->pre == 0)
					break ;
				write(1, &str[i++], 1);
				(*ret)++;
			}
	if (con->minus_pre == 0)
		f_len = con->width - len;
	else
		f_len = con->pre - len;
	while (f_len-- > 0)
	{
		if (con->zero == 1 && con->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*ret)++;
	}
	if (con->minus == 0 && con->minus_pre == 0)
		while (str[i])
		{
			if (con->dot == 1 && con->pre == 0)
				return (*ret);
			write(1, &str[i++], 1);
			(*ret)++;
		}
	return (*ret);
}
/*
int			print_morz(t_cond *con, int len, int *ret)
{
	int		f_len;

	if (con->minus_pre == 0)
	{
		f_len = con->width - len;
		if (con->dot == 1 && con->pre == 0)
			f_len = con->width;
	}
	else 
		f_len = con->width;
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
	if (con->minus_pre == 1)
	{
		if (con->p_star == 1 && con->width < con->pre)
		{
			con->dot = 0;
			con->minus_pre = 0;
			con->pre = con->width;
		}
		else
			con->width = con->pre;
		con->pre = 0;
	}
	if ((con->minus == 1 || con->minus_pre == 1))
		while (i < len)
		{
			if (con->dot == 1 && con->pre == 0)
				break ;
			write(1, &str[i++], 1);
			(*ret)++;
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

	if (con->width > con->pre && con->minus_pre == 0)
			f_len = con->width - len;
	else
		f_len = con->width - len;
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
	if (con->dot == 1 && con->width == 0 && con->pre == 0 && *str == '0')
		return (*ret);
	if (con->minus == 1 || con->minus_pre == 1)
		while (i < len)
		{
			if (con->dot == 1 && con->pre == 0 && *str == '0')
			{
				write(1, " ", 1);
				(*ret)++;
				break ;
			}
			write(1, &str[i++], 1);
			(*ret)++;
		}
	*ret = print_num_morz(con, len, ret);
	if (con->minus == 0 && con->minus_pre == 0)
		while (i < len)
		{
			if (con->dot == 1 && con->pre == 0 && *str == '0')
			{
				write(1, " ", 1);
				(*ret)++;
				return (*ret);
			}
			write(1, &str[i++], 1);
			(*ret)++;
		}
	return (*ret);
}*/
