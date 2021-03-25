/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:50:21 by junghan           #+#    #+#             */
/*   Updated: 2021/03/25 05:15:05 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sp(t_info *info, char **data)
{
	int	i;
	int	j;
	int	k;

	info->sp_count = info->sp2 + info->sp3 + info->sp4 + info->sp5;
	if ((info->sprite_arr = (t_s*)calloc(info->sp_count, sizeof(t_s))) == 0)
		error_exit("[ERROR] malloc error\n");
	i = -1;
	k = 0;
	while (data[++i])
	{
		j = -1;
		while (data[i][++j])
		{
			sp_get_offset(info, i, j, &k);
		}
	}
}

void	valid_check(char **map, t_info *info)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' ||
					map[i][j] == 'W' || map[i][j] == 'S')
			{
				flag++;
				start_dir(info, map[i][j], i, j);
				check_one_x(map, i, j, info);
			}
			if (map[i][j] == '0' || map[i][j] == '2' ||
				map[i][j] == '3' || map[i][j] == '4' || map[i][j] == '5')
				check_one_x(map, i, j, info);
		}
	}
	if (flag != 1)
		error_exit("[ERROR] map invalid \n");
}

char	*is_null(char *s1, char *s2)
{
	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	return (0);
}

void	parse_map(t_info *info)
{
	char	*line;
	char	*temp;
	char	*temp2;

	temp = 0;
	while (get_next_line(info->fd, &line) > 0)
	{
		if (temp == 0 || line == 0)
			temp2 = is_null(temp, line);
		else
			temp2 = ft_strjoin(temp, line);
		free(temp);
		temp = ft_strjoin(temp2, "!");
		free(temp2);
		free(line);
	}
	info->map = ft_split(temp, '!');
	free(temp);
	free(line);
	info->map_lines = 0;
	while (info->map[info->map_lines] != 0)
		info->map_lines++;
	valid_check(info->map, info);
	get_sp(info, info->map);
}
