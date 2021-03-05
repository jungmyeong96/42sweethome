/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:23:44 by daekim            #+#    #+#             */
/*   Updated: 2021/03/06 04:46:11 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			main_loop(t_info *p)
{
	calc_fl(p);
	calc_wa(p);
	calc_sp(p);
	draw(p);
	save_bmp(p);
	k_press(p);
	return (0);
}

void		info(t_info *p)
{
	p->move = 0.05;
	p->rot = 0.025;
	p->key_w = 0;
	p->key_s = 0;
	p->key_d = 0;
	p->key_a = 0;
	p->key_e = 0;
	p->key_q = 0;
	p->key_al = 0;
	p->key_ar = 0;
	p->key_ws = 0;
	p->key_ad = 0;
	p->key_qe = 0;
	p->key_aa = 0;
	p->sp_count = 0;
	p->is_save = 0;
}

void		open_cub(char *file, t_info *p)
{
	int		file_len;
	char	file_ext[5];
	int		check;

	file_len = (int)ft_strlen(file);
	if (format(file, ".cub") != 1)
		putstr_err("Error : no such cub file!");
	p->data.fd = open(file, O_RDONLY);
	if (p->data.fd == -1)
		putstr_err("Error : no such file!\n");
}

void		check_ar(int ac, char **av, t_info *p)
{
	if (ac > 3)
		putstr_err("Error : To many arguments!\n");
	if (ac < 2)
		putstr_err("Error : To few arguments!\n");
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) == 0)
			p->is_save = 1;
		else
			putstr_err("Error : does't save command");
	}
}

int			main(int ac, char **av)
{
	t_info	p;

	p.mlx_p = mlx_init();
	info(&p);
	check_ar(ac, av, &p);
	open_cub(av[1], &p);
	get_file(&p);
	buf_mal(&p);
	maping(&p);
	p.win_p = mlx_new_window(p.mlx_p, p.data.win_w,
			p.data.win_h, "cub3d");
	p.img.img_p = mlx_new_image(p.mlx_p, p.data.win_w, p.data.win_h);
	p.img.data = (int *)mlx_get_data_addr(p.img.img_p, &p.img.bpp,
			&p.img.size_l, &p.img.endian);
	ft_press(&p);
	mlx_loop_hook(p.mlx_p, &main_loop, &p);
	mlx_loop(p.mlx_p);
}
