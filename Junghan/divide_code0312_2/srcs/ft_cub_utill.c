/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:57:56 by junghan           #+#    #+#             */
/*   Updated: 2021/03/11 20:24:36 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_only_digit(char *dig)
{
	int	i;

	i = 0;
	while (dig[i])
	{
		if (dig[i] < '0' && dig[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_extation(char *mapfile, char *extation)
{
	char	*check;
	int		len;

	check = ft_strrchr(mapfile, '.');
	if (!check)
		return (0);
	len = ft_strlen(check);
	if (ft_strncmp(check, extation, len) == 0)
		return (1);
	else
		return (0);
}

void	error_exit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(0);
}

int			is_space(char *d, t_info *p)
{
	int		i;

	i = -1;
	while (d[++i] && p->check_ele[6] < 1)
	{
		if ((d[i] >= 9 && d[i] <= 13) || d[i] == ' ')
			continue ;
		return (0);
	}
	return (1);
}
