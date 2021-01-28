/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:32 by daekim            #+#    #+#             */
/*   Updated: 2021/01/28 23:14:00 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_str(char *str, t_cond *con, int len, int ret)
{
	int		i;
	int		f_len;

	i = 0;
	if (con->minus == 1)
		while (i < len)
		{
			write(1, &str[i++], 1);
			ret++;
		}
	f_len = con->width - len;
	while (f_len-- > 0)
	{
		if (con->zero == 1 && con->dot == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		ret++;
	}
	if (con->minus == 0)
		while (i < len)
		{
			write(1, &str[i++], 1);
			ret++;
		}
	return (ret);
}
