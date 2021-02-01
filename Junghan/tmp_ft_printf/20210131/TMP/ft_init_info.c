/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:40:52 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 17:50:34 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_info(t_info *info)
{
	info->f_hyphen = 0;
	info->f_zero = 0;
	info->w_num = 0;
	info->p_num = 0;
	info->p_existence = 0;
	info->p_asterisk = 0;
}