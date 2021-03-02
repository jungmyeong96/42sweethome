/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 03:49:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 05:10:41 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		open_cub(char *file, t_info *p)
{
	int		file_len;
	char	file_ext[5];
	int		check;
	
	file_len = (int)ft_strlen(file);
	if (format(file, ".cub"))
		putstr_err("Error : no such cub file!");
	p->data.fd = open(file, O_RDONLY);
	if (p->data.fd == -1)
		putstr_err("Error : no such file!\n");
}

void		check_ar(int ac)
{
	if (ac > 3)
		putstr_err("Error : To many arguments!\n");
	if (ac < 2)
		putstr_err("Error : To few arguments!\n");
}

int			main(int ac, char **av)
{
	t_info p;

	check_ar(ac);
	open_cub(av[1], &p);
//	get_file(&p);
	maping(&p); 
	return (0);
}
