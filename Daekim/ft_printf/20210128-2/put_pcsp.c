/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:13:49 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 23:18:54 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_per(char c, t_cond *con)
{
	int		ret;
	int		len;

	ret = 0;
	len = con->width - 1;
	if (con->minus == 1)
		write(1, &c, 1);
	while (len--)
	{
		if (con->zero == 1 && con->dot == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ret++;
	}
	if (con->minus == 0)
		write(1, &c, 1);
	ret++;
	return (ret);
}

int			put_chr(va_list ap, t_cond *con)
{
	int		ret;
	int		output;
	int		len;

	ret = 0;
	output = va_arg(ap, int);
	if (con->minus == 1)
		write(1, &output, 1);
	len = con->width - 1;
	while (len--)
	{
		if (con->zero == 1 && con->dot == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ret++;
	}
	if (con->minus == 0)
		write(1, &output, 1);
	ret++;
	return (ret);
}

int			put_str(va_list ap, t_cond *con)
{
	int		ret;
	char	*output;
	int		len;

	ret = 0;
	output = va_arg(ap, char *);
	if (!output)
	{
		output = ft_strdup("(null)");
		while (output)
		{
			write(1, &output, 1);
			output++;
		}
		free(output);
		output = 0;
		return (6);
	}
	len = ft_strlen(output);
	if (len > con->pre)
		len = con->pre;
	ret = print_str(output, con, len, ret);
	return (ret);
}

int			put_poi(va_list ap, t_cond *con)
{
	int		ret;
	char	*output;
	void	*num;
	int		len;

	ret = 0;
	num = va_arg(ap, void *);
	output = ten_hex((ssize_t)num, con);
	len = ft_strlen(output);
	ret = print_str(output, con, len, ret);
	free(output);
	output = 0;
	return (ret);
}
