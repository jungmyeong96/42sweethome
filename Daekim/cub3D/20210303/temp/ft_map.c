/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:49:56 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 20:38:33 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		check_one_y2(char **d, int i, int j, int num)
{
	int		y;
	int		len;

	y = i;
	while (++y <= num)
	{
		if (y == num)
			putstr_err("Error : map invalid");
		len = ft_strlen(d[y]);
		if (len < j && d[y - 1][j] != 1)
			putstr_err("Error : map invalid");
		if (d[y][j] == '1')
			break ;
		check_char(d[y][j]);
	}
}

void		check_one_y(char **d, int i, int j, int num)
{
	int		y;
	int		len;

	y = i;
	while (--y >= -1)
	{
		if (y == -1)
			putstr_err("Error : map invalid");
		len = ft_strlen(d[y]);
		if (len < j && d[y + 1][j] != 1)
		putstr_err("Error : map invalid");
		if (d[y][j] == '1')
			break ;
		check_char(d[y][j]);
	}
	check_one_y2(d, i, j, num);
}

void		check_one_x(char **d, int i, int j, int num)
{
	int x;
	int len;

	x = j;
	while (--x >= 0)
	{
		if (d[i][x] == '1')
			break;
		check_char(d[i][x]);
		if (x == 0)
			putstr_err("Error : map invalid");
	}
	x = j;
	while (d[i][x] != '\0')
	{
		if (d[i][x] == '1')
			break;
		check_char(d[i][x]);
		if (d[i][++x] == '\0')
			putstr_err("Error : map invalid");
	}
	check_one_y(d, i, j, num);
}

void		valid_check(char **d, int num)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = 0;
	flag = 0;
	while (d[++i])
	{
		j = -1;
		while (d[i][++j])
		{
			if (d[i][j] == 'N' || d[i][j] == 'E' || d[i][j] == 'W' || d[i][j] == 'S')
			{
				flag++;
				check_one_x(d, i, j, num);
			}
			if (d[i][j] == '0')
				check_one_x(d, i, j, num);
		}
	}
	if	(flag != 1)
		putstr_err("Error : map invalid");

	i = 0;
	while (d[i])
		printf("%s\n", d[i++]);
}

void		maping(t_info *p)
{
	char	*line;
	char	*temp;
	char	**data;
	int		num;

	temp = 0;
	while (get_next_line(p->data.fd, &line) > 0)
	{
		temp = ft_strjoin2(temp, line);
		temp = ft_strjoin2(temp, "!");
		free(line);
		line = 0;
	}
	data = ft_split(temp, '!');
	num = 0;
	while (data[num] != 0)
		num++;
	valid_check(data, num);

//	p->data.line;
}
