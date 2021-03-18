/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:48:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:46:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		get_pos(t_info *p, int j, int i)
{
	if (j >= 3 * ((p->data.win_h / 5) / 7)
			&& j <= 4 * ((p->data.win_h / 5) / 7))
		if (i >= 3 * ((p->data.win_w / 4) / 7)
				&& i <= 4 * ((p->data.win_w / 4) / 7))
			p->minimap[j][i] = 0xFD93F9;
}

void		color_mini(t_info *p, int i, int j)
{
	if ((j / ((p->data.win_h / 5) / 7) + (int)p->pos_x >= 3) &&
		(j / ((p->data.win_h / 5) / 7) + (int)p->pos_x <= p->data.m_num + 2))
	{
		if (i / ((p->data.win_w / 4) / 7) + (int)p->pos_y >= 3 &&
			i <= (p->data.win_w - ((p->data.win_w / 4) / 7) * 2))
		{
			if (p->data.map[j / ((p->data.win_h / 5) / 7) + (int)p->pos_x - 3]
				[i / ((p->data.win_w / 4) / 7) + (int)p->pos_y - 3] == '1')
				p->minimap[j][i] = 0xFF0000;
			else if (p->data.map[(j / ((p->data.win_h / 5) / 7) +
					(int)p->pos_x) - 3][i / ((p->data.win_w / 4) / 7) +
					(int)p->pos_y - 3] == '2')
				p->minimap[j][i] = 0x00FF00;
			else if (p->data.map[j / ((p->data.win_h / 5) / 7) +
					(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
					(int)p->pos_y - 3] == '0')
				p->minimap[j][i] = 0x0000FF & 8355711 +
					p->buf[j][i + p->data.win_w * 3 / 4];
		}
	}
	else
		p->minimap[j][i] = 0x0000FF & 8355711 +
			p->buf[j][i + p->data.win_w * 3 / 4];
}

void		show_mini(t_info *p)
{
	int		i;
	int		j;

	j = -1;
	while (++j < p->data.win_h / 5)
	{
		i = -1;
		while (++i < p->data.win_w / 4)
		{
			color_mini(p, i, j);
			get_pos(p, j, i);
		}
	}
}

void		map_base(t_info *p)
{
	int		i;
	int		j;

	j = 0;
	while (j < p->data.win_h / 5)
	{
		i = 0;
		while (i < p->data.win_w / 4)
		{
			p->minimap[j][i] = 0x0000FF & 8355711 +
				p->buf[j][i + p->data.win_w * 3 / 4];
			i++;
		}
		j++;
	}
}

void		minimap(t_info *p)
{
	int		i;
	int		j;
	int		k;

	map_base(p);
	show_mini(p);
	j = 0;
	while (j < p->data.win_h / 5)
	{
		i = p->data.win_w * 3 / 4;
		k = 0;
		while (i < p->data.win_w)
		{
			p->buf[j][i] = p->minimap[j][k];
			p->minimap[j][k] = 0;
			k++;
			i++;
		}
		j++;
	}
}
