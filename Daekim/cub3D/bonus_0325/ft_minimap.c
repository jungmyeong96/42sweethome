/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
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

void		color_mini2(t_info *p, int i, int j)
{
	if (p->data.map[j / ((p->data.win_h / 5) / 7) +
			(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
			(int)p->pos_y - 3] == '2')
		p->minimap[j][i] = 0xFF0000;
	else if (p->data.map[j / ((p->data.win_h / 5) / 7) +
			(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
			(int)p->pos_y - 3] == '3')
		p->minimap[j][i] = 0x33FF00;
	else if (p->data.map[j / ((p->data.win_h / 5) / 7) +
			(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
			(int)p->pos_y - 3] == '4')
		p->minimap[j][i] = 0xFF9933;
	else if (p->data.map[j / ((p->data.win_h / 5) / 7) +
			(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
			(int)p->pos_y - 3] == '5')
		p->minimap[j][i] = 0x0033FF;
	else if (p->data.map[j / ((p->data.win_h / 5) / 7) +
			(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
			(int)p->pos_y - 3] == '6')
		p->minimap[j][i] = 0x99FFFF;
}

void		color_mini(t_info *p, int i, int j)
{
	if ((j / (int)((p->data.win_h / 5) / 7) + (int)p->pos_x >= 3) &&
		j / ((p->data.win_h / 5) / 7) + (int)p->pos_x - 3 < p->data.m_num)
	{
		if (i / (int)((p->data.win_w / 4) / 7) + (int)p->pos_y >= 3 &&
				i / ((p->data.win_w / 4) / 7) + (int)p->pos_y - 3
				< (int)ft_strlen(p->data.map[j / ((p->data.win_h / 5) / 7) +
					(int)p->pos_x - 3]))
		{
			if (p->data.map[j / ((p->data.win_h / 5) / 7) + (int)p->pos_x - 3]
				[i / ((p->data.win_w / 4) / 7) + (int)p->pos_y - 3] == '1')
				p->minimap[j][i] = 0x660033;
			else if (p->data.map[j / ((p->data.win_h / 5) / 7) +
					(int)p->pos_x - 3][i / ((p->data.win_w / 4) / 7) +
					(int)p->pos_y - 3] == '0')
				p->minimap[j][i] = 0x0000FF & 8355711 +
					p->buf[j][i + p->data.win_w * 3 / 4];
			else
				color_mini2(p, i, j);
		}
	}
	else
		p->minimap[j][i] = 0x0000FF & 8355711 +
			p->buf[j][i + p->data.win_w * 3 / 4];
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

void		minimap(t_info *p)
{
	int		i;
	int		j;
	int		k;

	map_base(p);
	j = 0;
	while (j < p->data.win_h / 5)
	{
		i = p->data.win_w * 3 / 4;
		k = 0;
		while (i < p->data.win_w && k < (int)p->data.win_w / 4)
		{
			p->buf[j][i] = p->minimap[j][k];
			p->minimap[j][k] = 0;
			k++;
			i++;
		}
		j++;
	}
}
