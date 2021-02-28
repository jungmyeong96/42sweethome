/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 06:51:49 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	fc_color(t_info *p, char *rgb, int n)
{

}

static void	tex_data(t_info *p, char *xpm_p, int n)
{
	int		fd;

	if (xpm_path == 0 || ft_format(xpm_p, ".xpm"))
		putstr_err("Error : no such path to xpm!");
	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		putstr_err("Error : no such xpm!");
	close(fd);
	p->texture[n] = xpm_p;
}

static void	screen_size(t_info *p, char *w, char *h)
{
	if (win_w == 0 || win_h == 0)
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
}

static int	check_data(t_info *p, char **data)
{
	if (ft_strcmp(data[0], "R"))
		screen_size(p, data[1], data[2]);
	else if (ft_strcmp(data[0], "NO"))
		tex_data(p, data[1], 0);
	else if (ft_strcmp(data[0], "SO"))
		tex_data(p, data[1], 1);
	else if (ft_strcmp(data[0], "WE"))
		tex_data(p, data[1], 2);
	else if (ft_strcmp(data[0], "EA"))
		tex_data(p, data[1], 3);
	else if (ft_strcmp(data[0], "S"))
		tex_data(p, data[1], 4);
	else if (ft_strcmp(data[0], "F"))
		fc_color(p, data[1], 5);
	else if (ft_strcmp(data[0], "C"))
		fc_color(p, data[1], 6);
	else
		return (-1);
	return (0);
}

void		get_file(t_info *p)
{
	char	*line;
	int		element;
	char	**data;

	while (get_next_line(s->fd, &line) > 0)
	{
		if (*line = '\0')
			continue ;
		data = ft_split(line, ' ');
		if (data == 0)
			putstr_err("Error : split fail");
		element = check_data(p, data);
		free_dou(data);
		if (element == -1)
			break ;
		free (line);
	}
	p->data.line = line;
}
