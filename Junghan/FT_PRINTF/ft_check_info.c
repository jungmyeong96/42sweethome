/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:16 by junghan           #+#    #+#             */
/*   Updated: 2021/02/02 13:13:10 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_flag(char *spec, t_info *info)
{
	char	*flags;
	char	*tmp;
	char	*is_flag;

	tmp = spec;
	flags = "-0";
	while (tmp && ((is_flag = ft_strchr(flags, *tmp)) != 0))
	{
		if (tmp && (*is_flag) == '-')
			info->f_hyphen = YES;
		else if (tmp && (*is_flag) == '0')
			info->f_zero = YES;
		tmp++;
	}
	if (tmp == 0)
		return (0);
	return (tmp);
}

int		ft_num_ast(va_list *ap, char **spec, int *error, t_info *info)
{
	int			result;

	result = 0;
	if (**spec && ('0' <= **spec && **spec <= '9'))
	{
		while ('0' <= **spec && **spec <= '9')
		{
			if (result > 2147483646)
				return (0);
			result = result * 10 + ((**spec) - '0');
			if (!(++(*spec)))
				return (0);
		}
	}
	else if (*spec && **spec == '*' && result == 0)
	{
		(*spec)++;
		if (info->p_existence == DOTNUM)
			info->p_asterisk = YES;
		if ((result = va_arg(*ap, int)) > 2147483646)
			return (0);
	}
	*error = NO;
	return (result);
}

char	*ft_check_width(va_list *ap, char *spec, t_info *info)
{
	int		width_num;
	int		error;
	char	*tmp;

	tmp = spec;
	error = YES;
	width_num = 0;
	if ((!(width_num = ft_num_ast(ap, &tmp, &error, info)))
			&& error == YES)
		return (0);
	if (width_num < 0)
	{
		width_num *= -1;
		info->f_hyphen = YES;
	}
	info->w_num = width_num;
	return (tmp);
}

char	*ft_check_precision(va_list *ap, char *spec, t_info *info)
{
	int		pre_num;
	int		error;
	char	*tmp;
	int		sign;

	tmp = spec;
	error = YES;
	sign = 1;
	pre_num = 0;
	if (*tmp == '.')
	{
		if (++tmp && (*tmp) == '-')
		{
			sign *= -1;
			tmp++;
		}
		if (*tmp && (!('0' <= *tmp && *tmp <= '9') && (*tmp) != '*'))
			info->p_existence = ONLYDOT;
		else
			info->p_existence = DOTNUM;
		if ((!(pre_num = ft_num_ast(ap, &tmp, &error, info))) && error == YES)
			return (0);
	}
	info->p_num = (pre_num * sign);
	return (tmp);
}

char	*ft_check_info(va_list *ap, const char *spec, t_info *info)
{
	char *tmp;

	if (!ap || !spec)
		return (0);
	tmp = (char *)spec;
	if ((tmp = ft_check_flag(tmp, info)) == 0)
		return (0);
	if ((tmp = ft_check_width(ap, tmp, info)) == 0)
		return (0);
	if ((tmp = ft_check_precision(ap, tmp, info)) == 0)
		return (0);
	return (tmp);
}
