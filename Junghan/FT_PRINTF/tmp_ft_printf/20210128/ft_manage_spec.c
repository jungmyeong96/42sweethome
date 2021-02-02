/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:39:08 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 17:01:31 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_manage_spec(va_list ap, const char *spec, t_info info)
{
	if (*spec == '%')
		if (!ft_apply_to_percent(ap, info))
			return (0);
	else if (*spec == 'c')
		if (ft_apply_to_char(ap, info))
			return (0);
	else if (*spec == 's')
		if (ft_apply_to_str(ap, info))
			return (0);
	else if (*spec == 'p')
		if (ft_apply_to_pointer(ap, info))
			return (0);
	else if (*spec == 'd' || *spec == 'i')
		if (ft_apply_to_int(ap, info))
			return (0);
	else if (*spec == 'u')
		if (ft_apply_to_unint(ap, info))
			return (0);
	else if (*spec == 'x' || *spec == 'X')
		if (ft_apply_to_hex(ap, info))
			return (0);
	else
		return (0);
	return (spec);
}
