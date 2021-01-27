/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:27:08 by junghan           #+#    #+#             */
/*   Updated: 2021/01/21 16:01:03 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *spec, ...)
{
	va_list ap;
	int		count;

	va_start(ap, spec);
	if(count = ft_parse_arg(ap,spec) < 0)
		return (0);
	va_end(ap);

	return (count);
}
