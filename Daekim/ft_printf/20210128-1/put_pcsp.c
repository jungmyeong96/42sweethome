/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:13:49 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 16:30:35 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_per(char c)
{
	int		ret;

	ret = 0;
	write(1, &c, 1);
	ret++;
	return (ret);
}

int			put_chr(va_list ap)
{
	int		ret;
	int		output;

	ret = 0;
	output = va_arg(ap, int);
	write(1, &output, 1);
	ret++;
	return (ret);
}

int			put_str(va_list ap)
{
	int		ret;
	char	*output;

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
		return (6);
	}
	while (output[ret])
		write(1, &output[ret++], 1);
	return (ret);
}

int			put_poi(va_list ap)
{
	int		ret;
	char	*output;
	void	*num;
	int		i;

	ret = 0;
	num = va_arg(ap, void *);
	output = ten_hex((ssize_t)num);
	i = 0;
	while (output[i])
	{
		write(1, &output[i], 1);
		i++;
		ret++;
	}
	free(output);
	output = 0;
	return (ret);
}
