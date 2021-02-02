/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:33:56 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 14:46:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_arg(va_list *ap, const char *format)
{
	const char	*curr;
	t_info		spec_info;

	curr = format;
	while (*curr)
	{
		if (*curr == '%')
		{
			curr++;
			ft_init_info(&spec_info);
			if (!(curr = (const char *)ft_check_info(ap, curr, &spec_info)))
				return (-1);
			if (!(curr = ft_manage_spec(ap, curr, spec_info)))
				return (-1);
		}
		else
			ft_putchar_fd(*curr, 1);
		curr++;
	}
	return (0);
}
