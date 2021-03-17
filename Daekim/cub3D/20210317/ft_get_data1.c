/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 03:54:05 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		tex_buf(t_info *p)
{
	if (!(p->texture = (int **)ft_calloc(12, sizeof(int *))))
		putstr_err("Error : tex first allocate fail!\n");
	if (!(p->twh = (t_wh *)ft_calloc(8, sizeof(t_wh))))
		putstr_err("Error : tex_wh allocate fail!\n");
	if (!(p->check_ele = (int *)ft_calloc(7, sizeof(int))))
		putstr_err("Error : element allocate fail!\n");
}

static void	check_dup(t_info *p)
{
	int		i;

	i = -1;
	while (++i < 7)
	{
		if (p->check_ele[i] > 1)
			putstr_err("Error : element duplicate!\n");
		else if (p->check_ele[i] == 0)
			putstr_err("Error : wrong element!\n");
	}
}

static void	check_arg(t_info *p, char *d)
{
	if (ft_strncmp(d, "R", 2) == 0)
		p->check_ele[0] += 1;
	else if (ft_strncmp(d, "NO", 3) == 0)
		p->check_ele[1] += 1;
	else if (ft_strncmp(d, "SO", 3) == 0)
		p->check_ele[2] += 1;
	else if (ft_strncmp(d, "WE", 3) == 0)
		p->check_ele[3] += 1;
	else if (ft_strncmp(d, "EA", 3) == 0)
		p->check_ele[4] += 1;
	else if (ft_strncmp(d, "F", 2) == 0)
		p->check_ele[5] += 1;
	else if (ft_strncmp(d, "C", 2) == 0)
		p->check_ele[6] += 1;
}

static int	check_element(t_info *p, char **data)
{
	check_arg(p, data[0]);
	if (ft_strncmp(data[0], "R", 2) == 0)
		screen_size(p, data[1], data[2]);
	else if (ft_strncmp(data[0], "NO", 3) == 0)
		tex_data(p, data[1], 0);
	else if (ft_strncmp(data[0], "SO", 3) == 0)
		tex_data(p, data[1], 1);
	else if (ft_strncmp(data[0], "WE", 3) == 0)
		tex_data(p, data[1], 2);
	else if (ft_strncmp(data[0], "EA", 3) == 0)
		tex_data(p, data[1], 3);
	else if (ft_strncmp(data[0], "S", 2) == 0)
		tex_data(p, data[1], 4);
	else if (ft_strncmp(data[0], "F", 2) == 0)
		col_or_xpm(p, data[1], 5);
	else if (ft_strncmp(data[0], "C", 2) == 0)
		col_or_xpm(p, data[1], 6);
	else if (is_space(data[0], p) == 0)
		return (-1);
	else
		return (-1);
	if (p->check_ele[6] == 1)
		return (-1);
	return (0);
}

void		get_file(t_info *p)
{
	char	*line;
	int		element;
	char	**data;

	tex_buf(p);
	while (get_next_line(p->data.fd, &line) > 0)
	{
		if (*line == '\0')
		{
			free_one(line);
			continue ;
		}
		data = ft_split(line, ' ');
		if (data == 0)
			putstr_err("Error : split fail\n");
		if ((element = check_element(p, data)) == -1)
		{
			check_dup(p);
			free(p->check_ele);
		}
		free_dou(data);
		free_one(line);
		if (element == -1)
			break ;
	}
}
