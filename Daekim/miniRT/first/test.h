/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:27:15 by daekim            #+#    #+#             */
/*   Updated: 2021/02/20 21:32:55 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TEST_H
# define TEST_H

# include "mlx/mlx.h"
# include "vector.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_mlx
{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;

	t_vec	color;
	int		int_color;
}				t_mlx;

/*
#define ButtonPressMask	(1L<<2)
#define ButtonPress	4
#define ButtonReleaseMask	(1L<<3)
#define ButtonRelease	5
#define	KeyRelease 3
#define KeyPressMask	(1L<<0)
#define KeyReleaseMask	(1L<<1)
#define KeyPress	2
#define MotionNotify	6
#define ButtonMotionMask	(1L<<13)

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}				t_data;
*/
#endif
