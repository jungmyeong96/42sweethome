/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:31:49 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 16:24:33 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_tenlen(ssize_t n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ten_ten(ssize_t n)
{
	char	*output;
	int		len;
	int		i;

	len = ft_tenlen(n);
	if (!(output = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = len;
	if (n == 0)
		output[0] = '0';
	if (n < 0)
	{
		output[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		output[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}

int			ft_hexlen(size_t n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char		*ten_hex(size_t n)
{
	char	*output;
	int		len;
	int		i;

	len = ft_hexlen(n);
	if (!(output = (char *)ft_calloc((len + 3), sizeof(char))))
		return (0);
	i = len + 2;
	if (n == 0)
		output[2] = '0';
	while (n)
	{
		i--;
		if (n % 16 < 10)
			output[i] = (n % 16) + '0';
		else if (n % 16 >= 10)
			output[i] = (n % 16) + 'a' - 10;
		n /= 16;
	}
	output[0] = '0';
	output[1] = 'x';
	return (output);
}
