/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:23:44 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:42:40 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		rebase(t_info *p)
{
	int		i;

	i = -1;
	while (++i < 7)
		p->check_ele[i] = 0;
	free_dou(p->data.map);
	info(p);
}

void		next_stage(t_info *p)
{
	rebase(p);
	open_cub(p->stage, p);
	get_file(p);
	maping(p);
	p->img.img_p = mlx_new_image(p->mlx_p, p->data.win_w, p->data.win_h);
	p->img.data = (int *)mlx_get_data_addr(p->img.img_p, &p->img.bpp,
			&p->img.size_l, &p->img.endian);
	p->zero_w = p->data.win_w / 2;
	p->zero_h = p->data.win_h / 2;
	p->move_p = 0;
}
