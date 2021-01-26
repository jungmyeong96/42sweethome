/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:33:56 by junghan           #+#    #+#             */
/*   Updated: 2021/01/21 16:51:41 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_arg(va_list ap, const char *spec)
{
	const char	*curr;
	t_info		*spec_info;

	curr = spec;
	if(!(spec_info = malloc(sizeof(t_info))))
		return (-1);
	while(*curr)
	{
		if (*curr == '%')
		{
			curr++;
			ft_init_info(spec_info);
			if (!(curr = ft_check_info(ap, spec, spec_info)))
				return (-1);
			if(!(curr = ft_manage_spec(ap, curr)))
				return (-1);
			cur1r++;
		}
		else
			ft_putchar_fd(*curr, 1);
		curr++;
	}
	free(spec_info);
	spec_info = 0;
	return (0);
}
