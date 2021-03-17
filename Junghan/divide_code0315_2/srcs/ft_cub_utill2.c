/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utill2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:24:49 by junghan           #+#    #+#             */
/*   Updated: 2021/03/13 07:23:39 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
