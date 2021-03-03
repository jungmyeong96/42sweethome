/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/03 06:50:23 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
/*
static void	fc_color(t_info *p, char *rgb_data, int n)
{
	char	**rgb;
	int		bin;
	int		temp;
	int		i;

	if (!(rgb = ft_split(rgb_data, ',')))
		putstr_err("Error : rgb data fail!");
	i = 0;
	bin = 0;
	while (i < 3)
	{
		if (!rgb[i] || !ft_only_digit(rgb[i]))
			putstr_err("Error : no such rgb data!");
		temp = ft_atoi(rgb[i]);
		if (temp > 255 || temp < 0)
			putstr_err("Error : rgb range fail!");
		bin = bin * 256 + temp;
		i++;
	}
	if (n == 5)
		p->texture[n] = bin;
	else if (n == 6)
		p->texture[n] = bin;
	free_dou(rgb);
}*/

static void	tex_data(t_info *p, char *xpm_p, int n)
{
	int		fd;

	if (xpm_p == 0 || format(xpm_p, ".xpm") != 0)
		putstr_err("Error : no such path to xpm!");
	fd = open(xpm_p, O_RDONLY);
	if (fd == -1)
		putstr_err("Error : no such xpm!");
	close(fd);
	tex_in(p, p->texture[n], xpm_p, &p->img);
}

static void	screen_size(t_info *p, char *w, char *h)
{
	if (w == 0 || h == 0)
		putstr_err("Error : width or height empty!");
	if (ft_only_digit(w) == 0 || ft_only_digit(h) == 0)
		putstr_err("Error : width or height not digit!");
	p->data.win_w = ft_atoi(w);
	p->data.win_h = ft_atoi(h);
	if (p->data.win_w > 2560)
		p->data.win_w = 2560;
	if (p->data.win_w < 640)
		p->data.win_w = 640;
	if (p->data.win_h > 1440)
		p->data.win_h = 1440;
	if (p->data.win_h < 480)
		p->data.win_h = 480;
	if (p->data.win_w == 0 || p->data.win_h == 0)
		putstr_err("Error : screen size fail");
}

static int	check_element(t_info *p, char **data)
{
	if (ft_strncmp(data[0], "R", 1) == 0)
		screen_size(p, data[1], data[2]);
	else if (ft_strncmp(data[0], "NO", 2) == 0)
		tex_data(p, data[1], 0);
	else if (ft_strncmp(data[0], "SO", 2) == 0)
		tex_data(p, data[1], 1);
	else if (ft_strncmp(data[0], "WE", 2) == 0)
		tex_data(p, data[1], 2);
	else if (ft_strncmp(data[0], "EA", 2) == 0)
		tex_data(p, data[1], 3);
	else if (ft_strncmp(data[0], "S", 1) == 0)
		tex_data(p, data[1], 4);
	else if (ft_strncmp(data[0], "F", 1) == 0)
		tex_data(p, data[1], 5);
	else if (ft_strncmp(data[0], "C", 1) == 0)
		tex_data(p, data[1], 6);
	return (0);
}

void		get_file(t_info *p)
{
	char	*line;
	int		element;
	char	**data;

	while (get_next_line(p->data.fd, &line) > 0)
	{
		if (*line == '\0')
			continue ;
		data = ft_split(line, ' ');
		if (data == 0)
			putstr_err("Error : split fail");
		element = check_element(p, data);
		if (data[0][0] == 'C')
			element = -1;
		free_dou(data);
		if (element == -1)
			break ;
		free(line);
	}
}
