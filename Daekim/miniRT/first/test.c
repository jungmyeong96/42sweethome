#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
/*
#define ButtonPressMask	(1L<<2)
#define ButtonPress	4
#define ButtonReleaseMask	(1L<<3)
#define ButtonRelease	5
#define KeyRelease	3
#define KeyPressMask	(1L<<0)
#define KeyReleaseMask	(1L<<1)
#define KeyPress	2
#define MotionNotify	6
#define ButtonMotionMask	(1L<<13)
*/
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

int			esc_key(int key, t_data *data)
{
//	printf("Key in Win : %d\n", key);
	if (key == 53)
		exit(0);
	if (key == 0)
		mlx_clear_window(data->mlx, data->win);
}

int			Key_release(int key, void *p)
{
//	printf("rel_key: %d\n", key);
	if (key == 53)
		exit(0);
}

int			mouse_press(int button, int x, int y, void *p)
{
	printf("Mouse_button in Win, button %d at %dx%d.\n", button, x, y);
}

int 		mouse_release(int button, int x, int y, void *p)
{
	printf("button_num: %d , release at %dx%d\n", button, x, y);
}

int 		mouse_pos(int x, int y, t_data *data)
{
	printf("mouse_pos %dx%d\n", x, y);
	mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

int			main()
{
	void	*mlx_p;
	void	*win_p;

	mlx_p = mlx_init();
	win_p = mlx_new_window(mlx_p, 500, 500, "test");
	mlx_key_hook(win_p, esc_key, 0);
//	mlx_mouse_hook(win_p, mouse, 0);
//	mlx_string_put(mlx_p, win_p, 5, 20, 0xFF99FF, "String input");
	int		x;
	int		y;
	int		color;

	x = 500;
	while (x--)
	{
		y = 500;
		while (y--)
		{
			color = (x * 255) / 500 + ((((500 - x) * 255) / 500) << 16) + (((y * 255) / 500) << 8);
			mlx_pixel_put(mlx_p, win_p, x, y, color);
		}
	}
	mlx_loop(mlx_p);
/*
	t_data data;

	data.mlx = mlx_init();sdf
	data.width = 500;
	data.height = 500;
	data.win = mlx_new_window(data.mlx, data.width, data.height, "test");
	data.img = mlx_new_image(data.mlx, 500, 500);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, KeyPress, KeyPressMask, esc_key, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, Key_release, &data);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, mouse_press, &data);
	mlx_hook(data.win, ButtonRelease, ButtonReleaseMask, mouse_release, &data);
	mlx_hook(data.win, MotionNotify,ButtonMotionMask, mouse_pos, &data);
	mlx_loop(data.mlx);*/
}
