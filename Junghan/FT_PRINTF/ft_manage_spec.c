/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:39:08 by junghan           #+#    #+#             */
/*   Updated: 2021/02/02 13:01:13 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_manage_spec(va_list *ap, const char *spec,
		t_info info, int *result)
{
	int error_check;

	error_check = 0;
	if (*spec == '%')
		error_check = ft_apply_to_percent(spec, info, result);
	else if (*spec == 'c')
		error_check = ft_apply_to_char(ap, spec, info, result);
	else if (*spec == 's')
		error_check = ft_apply_to_str(ap, spec, info, result);
	else if (*spec == 'p')
		error_check = ft_apply_to_pointer(ap, spec, info, result);
	else if (*spec == 'd' || *spec == 'i')
		error_check = ft_apply_to_int(ap, info, result);
	else if (*spec == 'u')
		error_check = ft_apply_to_unint(ap, info, result);
	else if (*spec == 'x' || *spec == 'X')
		error_check = ft_apply_to_hex(ap, spec, info, result);
	else
		return (0);
	if (!error_check)
		return (0);
	return (spec);
}
