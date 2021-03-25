/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:49:28 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:47:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sp_offset2(t_info *p, int i, int j, int *k)
{
	if (p->data.map[i][j] == '5')
	{
		p->sprite[*k].x = i + 0.5;
		p->sprite[*k].y = j + 0.5;
		p->sprite[(*k)++].tex = 13;
	}
	else if (p->data.map[i][j] == '6')
	{
		p->sprite[*k].x = i + 0.5;
		p->sprite[*k].y = j + 0.5;
		p->sprite[(*k)++].tex = 14;
	}
}

void	sp_offset(t_info *p, int i, int j, int *k)
{
	if (p->data.map[i][j] == '2')
	{
		p->sprite[*k].x = i + 0.5;
		p->sprite[*k].y = j + 0.5;
		p->sprite[(*k)++].tex = 10;
	}
	else if (p->data.map[i][j] == '3')
	{
		p->sprite[*k].x = i + 0.5;
		p->sprite[*k].y = j + 0.5;
		p->sprite[(*k)++].tex = 11;
	}
	else if (p->data.map[i][j] == '4')
	{
		p->sprite[*k].x = i + 0.5;
		p->sprite[*k].y = j + 0.5;
		p->sprite[(*k)++].tex = 12;
	}
	else
		sp_offset2(p, i, j, k);
}

void	count_item(char sp, t_info *p)
{
	if (sp == '2')
		p->sp2++;
	else if (sp == '3')
		p->sp3++;
	else if (sp == '4')
		p->sp4++;
	else if (sp == '5')
		p->sp5++;
	else if (sp == '6')
		p->sp6++;
}

void	sp_data(t_info *p, char **data)
{
	int		fd;
	int		n;

	n = 0;
	while (++n < 7)
	{
		if (data == 0 || format(data[n], ".xpm") != 1)
			putstr_err("Error : no such path to xpm!\n");
		fd = open(data[n], O_RDONLY);
		if (fd == -1)
			putstr_err("Error : no such xpm!\n");
		close(fd);
		if (n == 6)
			p->dis_wp = ft_strdup(data[n]);
		tex_in(p, n + 9, data[n], &p->img);
	}
}
