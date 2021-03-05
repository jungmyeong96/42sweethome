/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:29:43 by daekim            #+#    #+#             */
/*   Updated: 2021/03/06 00:06:54 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		image_bmp(t_info *p, t_save *s)
{
	int		i;
	int		j;
	int		x;
	int		y;

	j = -1;
	while (++j < p->data.win_h)
	{
		i = -1;
		while (++i < p->data.win_w)
		{
			x = i;
			y = p->data.win_h - 1 - j;
			s->color_b = p->img.data[y * p->data.win_w + x];
			write(s->fd_b, &s->color_b, 3);
		}
		i = -1;
		while (++i < (4 - (p->data.win_w * 3) % 4) % 4)
			write(s->fd_b, &s->pad, 1);
	}
}

void		header_set(unsigned char *header, int bit)
{
	header[0] = (unsigned char)(bit);
	header[1] = (unsigned char)(bit >> 8);
	header[2] = (unsigned char)(bit >> 16);
	header[3] = (unsigned char)(bit >> 24);
}

void		header_bmp(t_info *p, t_save *s)
{
	int		i;

	i = 0;
	while (i < 14)
		s->header[i++] = 0;
	s->header[0] = 'B';
	s->header[1] = 'M';
	s->header[10] = 54;
	i = 0;
	while (i < 40)
		s->data[i++] = 0;
	s->data[0] = 40;
	s->data[12] = 1;
	s->data[14] = 24;
	i = 0;
	while (i < 3)
		s->pad[i++] = 0;
	header_set(&s->header[2], s->size_b);
	header_set(&s->data[4], p->data.win_w);
	header_set(&s->data[8], p->data.win_h);
	write(s->fd_b, s->header, 14);
	write(s->fd_b, s->data, 40);
}

void		save_bmp(t_info *p)
{
	if (p->is_save == 1)
	{
		p->save.size_b = 54 + 3 * p->data.win_w * p->data.win_h;
		if ((p->save.fd_b = open("save.bmp", O_CREAT | O_WRONLY, S_IRWXU)) < 0)
			putstr_err("Error : create bmp fail!");
		header_bmp(p, &p->save);
		image_bmp(p, &p->save);
		close(p->save.fd_b);
		p->is_save = 0;
	}
}
