/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 07:05:40 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	p ->line = line;
}

void		open_cub(char *file, f_info *p)
{
	int		file_len;
	char	file_ext[5];
	int		check;
	
	file_len = (int)ft_strlen(file);
	if (ft_format(file, ".cub"))
		putstr_err("Error : no such cub file!");
	p->fd = open(file, O_RDONLY);
	if (p->fd == -1)
		putstr_exit("Error : no such file!\n");
}

void		check_ar(int ac)
{
	if (ac > 3)
		putstr_exit("Error : To many arguments!\n");
	if (ac < 2)
		putstr_exit("Error : To few arguments!\n");
}

int			main(int ac, char **av)
{
	t_info *p;

	check_ar(ac);
	open_cub(av[1], p);
	get_file(p);
	return (0);
}
