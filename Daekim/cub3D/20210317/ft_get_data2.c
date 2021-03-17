/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/14 20:48:05 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		color_check(t_info *p, int rgb, int n)
{
	if (n == 5)
	{
		p->cal.f_rgb = 1;
		p->cal.color_f = rgb;
	}
	if (n == 6)
	{
		p->cal.c_rgb = 1;
		p->cal.color_c = rgb;
	}
}

void		fc_color(t_info *p, char *rgb_data, int n)
{
	char	**rgb;
	int		bin;
	int		temp;
	int		i;

	if (!(rgb = ft_split(rgb_data, ',')))
		putstr_err("Error : rgb data fail!\n");
	i = 0;
	bin = 0;
	while (i < 3)
	{
		if (!rgb[i] || !ft_only_digit(rgb[i]))
			putstr_err("Error : no such rgb data!\n");
		temp = ft_atoi(rgb[i]);
		if (temp > 255 || temp < 0)
			putstr_err("Error : rgb range fail!\n");
		bin = bin * 256 + temp;
		i++;
	}
	color_check(p, bin, n);
	free_dou(rgb);
}

void		tex_data(t_info *p, char *xpm_p, int n)
{
	int		fd;

	if (xpm_p == 0 || format(xpm_p, ".xpm") != 1)
		putstr_err("Error : no such path to xpm!\n");
	fd = open(xpm_p, O_RDONLY);
	if (fd == -1)
		putstr_err("Error : no such xpm!\n");
	close(fd);
	tex_in(p, n, xpm_p, &p->img);
}

void		screen_size(t_info *p, char *w, char *h)
{
	int		wh[2];

	if (w == 0 || h == 0)
		putstr_err("Error : width or height empty!\n");
	if (ft_only_digit(w) == 0 || ft_only_digit(h) == 0)
		putstr_err("Error : width or height not digit!\n");
	p->data.win_w = ft_atoi(w);
	p->data.win_h = ft_atoi(h);
	mlx_get_screen_size(p->mlx_p, &wh[0], &wh[1]);
	if (p->data.win_w > wh[0])
		p->data.win_w = wh[0];
	if (p->data.win_h > wh[1])
		p->data.win_h = wh[1];
	if (p->data.win_w < 640)
		p->data.win_w = 640;
	if (p->data.win_h < 480)
		p->data.win_h = 480;
	if (p->data.win_w == 0 || p->data.win_h == 0)
		putstr_err("Error : screen size fail\n");
}

void		col_or_xpm(t_info *p, char *d, int n)
{
	if (format(d, ".xpm") != 1)
		fc_color(p, d, n);
	else if (format(d, ".xpm") == 1)
		tex_data(p, d, n);
}
