/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:50:16 by junghan           #+#    #+#             */
/*   Updated: 2021/01/29 14:32:58 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_flag(char *spec, t_info *info)
{
	char *flags;
	char *tmp;
	char *is_flag;

	tmp = spec;
	flags = "-0";
	while (tmp && ((is_flag = ft_strchr(flags, *tmp)) != 0))
	{
		if (tmp && (*is_flag) == '-')
			info->f_hyphen = 1;
		else if (tmp && (*is_flag) == '0')
			info->f_zero = 1;
		tmp++;
	}
	if (tmp == 0)
		return (0);
	return (tmp);
}

int	ft_num_asterisk(va_list ap, char **spec, int *error)
{
	const char		*is_num;
	char			*check_num;
	long long int	result;

	check_num = "0123456789";
	result = 0;
	if (**spec && ('0' <= **spec && **spec <= '9'))
	{
		while ((is_num = ft_strchr(check_num, **spec)) != 0)
		{
			if (result > 2147483646)
				return (0);
			result = result * 10 + ((*is_num) - '0');
			if (!(++(*spec)))
				return (0);
		}
	}
	else if (*spec && **spec == '*' && result == 0)
	{
		(*spec)++;
		result = va_arg(ap, long long int);
		if (result > 2147483646)
			return (0);
	}
	*error = 0;
	return (result);
}

char	*ft_check_width(va_list ap, char *spec, t_info *info)
{
	int width_num;
	int	error;
	char *tmp;

	tmp = spec;
	error = 1;
	width_num = 0;
	if ((!(width_num = ft_num_asterisk(ap, &tmp, &error))) 
			&& error == 1)
		return (0);
	if (width_num < 0)
	{
		width_num *= -1;
		info->f_hyphen = 1;
	}
	info->w_num = width_num;
	return (tmp);
}

char	*ft_check_precision(va_list ap, char *spec, t_info *info)
{
	int	pre_num;
	int	error;
	char *tmp;
	int sign;

	tmp = spec;
	error = 1;
	sign = 1;
	pre_num = 0;
	if (*tmp == '.')
	{
		tmp++;
		if ((*tmp) == '-')
		{
			sign *= -1;
			tmp++;
		}
		if (*tmp && (!('0'<= *tmp && *tmp <= '9') && (*tmp) != '*'))
			info->p_existence = 2;
		if ((!(pre_num = ft_num_asterisk(ap, &tmp, &error))) && error == 1)
			return (0);
		if (info->p_existence != 2)
			info->p_existence = 1;
	}
	info->p_num = (pre_num * sign);
	return (tmp);
}

char	*ft_check_info(va_list ap, const char *spec, t_info *info)
{
	char *tmp;

	if (!ap || !spec)
		return (0);
	tmp = (char *)spec;
	/*flag*/
	if ((tmp = ft_check_flag(tmp, info)) == 0)
		return (0);
	/*width*/
	if ((tmp = ft_check_width(ap, tmp, info)) == 0)
		return (0);
	/*precision*/
	if ((tmp = ft_check_precision(ap, tmp, info)) == 0)
		return (0);
	return (tmp);
}
