/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:33:56 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 17:01:21 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_info(t_info info)
{
	printf("f_zero = %d\n",info.f_zero);
	printf("f_hyphen = %d\n",info.f_hyphen);
	printf("w_num = %d\n",info.w_num);
	printf("p_num = %d\n",info.p_num);
}

int	ft_parse_arg(va_list ap, const char *format)
{
	const char	*curr;
	t_info		spec_info;

	curr = format;
	while(*curr)
	{
		if (*curr == '%')
		{
			curr++;
			ft_init_info(&spec_info);
			if (!(curr = ft_check_info(ap, curr, &spec_info)))
				return (-1);
			if(!(curr = ft_manage_spec(ap, curr, spec_info)))
				return (-1);
			print_info(spec_info);
			printf("%c\n", *curr);
		}
		else
			ft_putchar_fd(*curr, 1);
		curr++;
	}
	//print_info(spec_info);
	return (0);
}
