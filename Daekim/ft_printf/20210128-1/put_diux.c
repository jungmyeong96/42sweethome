/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seou.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:15:51 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 16:01:24 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_hex(va_list ap, char c)
{
	int		ret;
	ssize_t	num;
	char	*result;
	int		i;

	ret = 0;
	num = va_arg(ap, unsigned int);
	result = ten_hex(num);
	i = 2;
	while (result[i])
	{
		if (c == 'X')
			result[i] = ft_toupper(result[i]);
		write(1, &result[i], 1);
		ret++;
		i++;
	}
	free(result);
	result = 0;
	return (ret);
}

int			put_uni(va_list ap)
{
	int		ret;
	ssize_t	num;
	char	*result;
	int		i;

	ret = 0;
	num = va_arg(ap, unsigned int);
	result = ten_ten(num);
	i = 0;
	while (result[i])
	{
		write(1, &result[i], 1);
		ret++;
		i++;
	}
	free(result);
	result = 0;
	return (ret);
}

int			put_dig(va_list ap)
{
	int		ret;
	ssize_t num;
	char	*result;
	int		i;

	ret = 0;
	num = va_arg(ap, int);
	result = ten_ten(num);
	i = 0;
	while (result[i])
	{
		write(1, &result[i], 1);
		ret++;
		i++;
	}
	free(result);
	result = 0;
	return (ret);
}
