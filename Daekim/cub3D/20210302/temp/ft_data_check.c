/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:28:09 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 20:02:03 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			check_char(int c)
{
	if (!(c == '0' || c == '1' || c == '2' ||
		   c == 'N' || c == 'E' || c == 'W' || c == 'S'))
		putstr_err("Error : map invalid");
}

void		check_back_len(char **d, int y, int j)
{
	int len;

	len = ft_strlen(d[y]);
	if (len < j && d[y + 1][j] != 1)
		putstr_err("Error : map invalid");
}

void		check_front_len(char **d, int y, int j)
{
	int len;

	len = ft_strlen(d[y]);
	if (len < j && d[y - 1][j] != 1)
		putstr_err("Error : map invalid");
}



