/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:13:19 by junghan           #+#    #+#             */
/*   Updated: 2021/03/08 13:07:09 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_mapfile(t_info *info, char *mapfile)
{
	if (!ft_check_extation(mapfile, ".cub"))
	{
		printf("[ERROR] Invalid file.\
				\n[CODE] Check tha extation of the file.\n");
		printf("\n[MAPFILE]:\n%s\n", mapfile);
		exit(0);
	}
	info->fd = open(mapfile, O_RDONLY);
	if (info->fd == -1)
	{
		printf("[ERROR] Invalid file.\
				\n[CODE] Check the status of the file.\n");
		exit(0);
	}
	return (info->fd);
}

void	arg_protect(t_info *info, int argc, char **argv)
{
	int i;
	if (argc > 3)
	{
		i = 0;
		while (++i < argc)
			;
		error_exit("[ERROR] Just put in two arguments.\n[CODE] \
				Too many arguments!\n\n");
	}
	if (argc < 2)
	{
		error_exit("[ERROR] Just put in two arguments.\n[CODE] \
				Too few arguments!\n\n[ARGUMENTS]:\nNONE\n");
		exit(0);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
			info->is_save = 1;
		else
			error_exit("[ERROR] does't save command\n[COMMAND] \
					put in --save\n\n");
	}
}
