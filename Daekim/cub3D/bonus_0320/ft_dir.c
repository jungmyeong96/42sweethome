/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 06:19:35 by daekim            #+#    #+#             */
/*   Updated: 2021/03/14 20:27:16 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		start_dir_we(t_info *p, char c)
{
	if (c == 'E')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (c == 'W')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}

void		start_dir(t_info *p, char c, int x, int y)
{
	p->pos_x = (double)x + 0.5;
	p->pos_y = (double)y + 0.5;
	if (c == 'N')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
	else
		start_dir_we(p, c);
}
