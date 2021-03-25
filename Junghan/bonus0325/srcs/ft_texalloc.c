/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 03:07:39 by junghan           #+#    #+#             */
/*   Updated: 2021/03/24 01:34:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		tex_wh(t_info *info, int n, t_img *i)
{
	info->texwh[n].tex_w = i->img_width;
	info->texwh[n].tex_h = i->img_height;
	if (!(info->texture[n] = (int *)ft_calloc(info->texwh[n].tex_w
					* info->texwh[n].tex_h, sizeof(int))))
		error_exit("Error : tex allocate fail!\n");
}

void		tex_buf(t_info *info)
{
	if (!(info->texture = (int **)ft_calloc(15, sizeof(int *))))
		error_exit("Error : tex first allocate fail!\n");
	if (!(info->texwh = (t_wh *)ft_calloc(15, sizeof(t_wh))))
		error_exit("Error : tex_wh allocate fail!\n");
	if (!(info->check_ele = (int *)ft_calloc(7, sizeof(int))))
		error_exit("Error : element allocate fail!\n");
}
