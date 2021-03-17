/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:22:58 by junghan           #+#    #+#             */
/*   Updated: 2021/03/16 02:52:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite_draw_p(t_sprite *sprite, t_info *info)
{
	sprite->sprite_hei = abs((int)(info->win_hei / sprite->transf_y))
		/ VDIV;
	sprite->drawstart_y = -(sprite->sprite_hei) / 2 + info->win_hei
		/ 2 + sprite->vmove_scr;
	if (sprite->drawstart_y < 0)
		sprite->drawstart_y = 0;
	sprite->drawend_y = sprite->sprite_hei / 2 + info->win_hei
		/ 2 + sprite->vmove_scr;
	if (sprite->drawend_y >= info->win_hei)
		sprite->drawend_y = info->win_hei - 1;
	sprite->sprite_wid = abs((int)(info->win_hei / sprite->transf_y))
		/ UDIV;
	sprite->drawstart_x = -(sprite->sprite_wid) / 2 + sprite->sprite_scr_x;
	if (sprite->drawstart_x < 0)
		sprite->drawstart_x = 0;
	sprite->drawend_x = sprite->sprite_wid / 2 + sprite->sprite_scr_x;
	if (sprite->drawend_x >= info->win_wid)
		sprite->drawend_x = info->win_wid - 1;
	put_in_spritebuf(sprite, info);
}

void	set_sprite_info(t_sprite *sprite, t_info *info, int i)
{
	sprite->vmove = 0.0;
	sprite->sprite_x = info->sprite_arr[sprite->sprite_ord[i]].x
		- info->pos_x;
	sprite->sprite_y = info->sprite_arr[sprite->sprite_ord[i]].y
		- info->pos_y;
	sprite->invdet = 1.0 / (info->plane_x * info->dir_y - info->dir_x
		* info->plane_y);
	sprite->transf_x = sprite->invdet * (info->dir_y * sprite->sprite_x
		- info->dir_x * sprite->sprite_y);
	sprite->transf_y = sprite->invdet * (-(info->plane_y)
		* sprite->sprite_x + info->plane_x * sprite->sprite_y);
	sprite->sprite_scr_x = (int)((info->win_wid / 2)
		* (1 + sprite->transf_x / sprite->transf_y));
	sprite->vmove_scr = (int)(sprite->vmove / sprite->transf_y) + info->pitch
		+ info->pos_z / sprite->transf_y;
	set_sprite_draw_p(sprite, info);
}

void	make_sprite_arr(t_sprite *sprite, t_info *info)
{
	int i;

	i = 0;
	while (i < info->sp_count)
	{
		sprite->sprite_ord[i] = i;
		sprite->sprite_dist[i] = ((info->pos_x - info->sprite_arr[i].x)
				* (info->pos_x - info->sprite_arr[i].x)
				+ (info->pos_y - info->sprite_arr[i].y)
				* (info->pos_y - info->sprite_arr[i].y));
		i++;
	}
	sort_sprite(info, sprite->sprite_ord,
			sprite->sprite_dist, info->sp_count);
}

void	calc_sprite(t_info *info)
{
	int i;

	if (!(info->sprite.sprite_ord = (int *)ft_calloc(info->sp_count,
					sizeof(int))))
		error_exit("[Error] sprite_ord allocation fail!\n");
	if (!(info->sprite.sprite_dist = (double *)ft_calloc(info->sp_count,
					sizeof(double))))
		error_exit("[Error] sprite_dist allocation fail!\n");
	make_sprite_arr(&info->sprite, info);
	i = 0;
	while (i < info->sp_count)
	{
		set_sprite_info(&info->sprite, info, i);
		i++;
	}
	free(info->sprite.sprite_ord);
	free(info->sprite.sprite_dist);
}
