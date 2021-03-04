/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:23:44 by daekim            #+#    #+#             */
/*   Updated: 2021/03/04 04:39:12 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			main_loop(t_info *p)
{
	calc_fl(p);
	calc_wa(p);
	calc_sp(p);
	draw(p);
	k_press(p);
	return (0);
}

void		buf_mal(t_info *p)
{
	int		i;

	if (!(p->buf = (int **)ft_calloc(p->data.win_h, sizeof(int *))))
		putstr_err("Error : buf allocate fail!");
	i = 0;
	while (i < p->data.win_h)
	{
		if (!(p->buf[i] = (int *)ft_calloc(p->data.win_w, sizeof(int))))
			putstr_err("Error : buf[i] allocate fail!");
		i++;
	}
	if (!(p->sp.zbuf = (double *)ft_calloc(p->data.win_w, sizeof(double))))
		putstr_err("Error : zbuf allocate fail!");
}

void		info(t_info *p)
{
/*	p->pos_x = 22;
	p->pos_y = 4;
	p->dir_x = 0;
	p->dir_y = -1;
	p->plane_x = -0.66;
	p->plane_y = 0;*/
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
//	color_wall(p);
//	tex_wall(p);
//	in_sprite(p);
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

	p.mlx_p = mlx_init();
	info(&p);
	check_ar(ac);
	open_cub(av[1], &p);
	get_file(&p);
	buf_mal(&p);
	maping(&p); 

	p.win_p = mlx_new_window(p.mlx_p, p.data.win_w, p.data.win_h, "second cub3d");
	p.img.img_p = mlx_new_image(p.mlx_p, p.data.win_w, p.data.win_h);
	p.img.data = (int *)mlx_get_data_addr(p.img.img_p, &p.img.bpp,
			&p.img.size_l, &p.img.endian);
	mlx_hook(p.win_p, X_KEY_PRESS, 0, &ft_keypress, &p);
//	mlx_hook(p.win_p, X_BUT_PRESS, 0, &ft_butpress, &p);
	mlx_hook(p.win_p, X_KEY_EXIT, 0, &ft_butpress, &p);

	mlx_loop_hook(p.mlx_p, &main_loop, &p);
	mlx_loop(p.mlx_p);
}
