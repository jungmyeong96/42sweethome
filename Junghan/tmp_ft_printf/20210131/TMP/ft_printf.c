/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:27:08 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 15:52:14 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	va_start(ap, format);
	if ((count = ft_parse_arg(&ap, format)) < 0)
		return (-1);
	va_end(ap);
	return (count);
}
