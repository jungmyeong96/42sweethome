/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/08 03:16:59 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		tex_buf(t_info *p)
{
	if (!(p->texture = (int **)ft_calloc(8, sizeof(int *))))
		putstr_err("Error : tex first allocate fail!");
	if (!(p->twh = (t_wh *)ft_calloc(8, sizeof(t_wh))))
		putstr_err("Error : tex_wh allocate fail!");
}

static int	check_element(t_info *p, char **data)
{
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
			putstr_err("Error : split fail");
		element = check_element(p, data);
		if (data[0][0] == 'C')
			element = -1;
		free_dou(data);
		free_one(line);
		if (element == -1)
			break ;
	}
}
