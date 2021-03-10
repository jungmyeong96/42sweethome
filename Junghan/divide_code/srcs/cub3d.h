/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:18:25 by junghan           #+#    #+#             */
/*   Updated: 2021/03/11 01:53:56 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "key_macro.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "structs.h"
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
void	error_exit(char *str);
int		ft_only_digit(char *dig);
int		is_space(char *d, t_info *p);
int		ft_check_extation(char *mapfile, char *extation);
void	free_dou(char **str);
void	key_up(t_info *info, t_keys *keys);
void	key_down(t_info *info, t_keys *keys);
void	key_right(t_info *info, t_keys *keys);
void	key_left(t_info *info, t_keys *keys);
void	turn_right(t_info *info, t_keys *keys);
void	turn_left(t_info *info, t_keys *keys);
void	key_updapt2(t_info *info, t_keys *keys);
void	key_updapt(t_info *info, t_keys *keys);
void	key_updapt2(t_info *info, t_keys *keys);
int		mouse_move(int x, int y, t_info *p);
void	ft_movement(t_info *info);
int		ft_key_press(int key_num, t_keys *keys);
int		ft_key_release(int key_num, t_keys *keys);
int		ft_click_exit(int keys, t_info *info);
void	save_bmp(t_info *info);
void    init_keys(t_keys *keys, t_info *info);
void    init_arr(t_info *info);
int     **alloc_arr(t_info *info);
void	start_dir(t_info *info, char c,int x, int y);
void	arg_protect(t_info *info, int argc, char **argv);
int		open_mapfile(t_info *info, char *mapfile);
void	get_file(t_info *info);
void	tex_data(t_info *p, char *xpm_p, int n);
void	col_or_xpm(t_info *info, char *d, int n);
void	parse_map(t_info *info);
void	check_one_x(char **map, int i, int j, t_info *info);
void	calc_floor(t_info *info, int y);
void	calc_wall(t_info *info, int x);
void	calc_sprite(t_info *info);
void	put_in_wallbuf(t_wall *wall, t_info *info, int x);
void	sort_sprite(t_info *info, int *obj, double *dist, int amount);
void	put_in_spritebuf(t_sprite *sprite, t_info *info);
