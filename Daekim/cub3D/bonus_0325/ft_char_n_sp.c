/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_n_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:28:09 by daekim            #+#    #+#             */
/*   Updated: 2021/03/08 18:39:07 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		check_char(int c)
{
	if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
		|| c == '6' || c == 'N' || c == 'E' || c == 'W' || c == 'S'))
		putstr_err("Error : map element invalid\n");
}

void		get_sp(t_info *p, char **d)
{
	int		i;
	int		j;
	int		k;

	p->sp_count = p->sp2 + p->sp3 + p->sp4 + p->sp5 + p->sp6;
	if ((p->sprite = (t_s *)ft_calloc(p->sp_count, sizeof(t_s))) == 0)
		putstr_err("Error : p->sprite allocate fail!\n");
	i = -1;
	k = 0;
	while (d[++i])
	{
		j = -1;
		while (d[i][++j])
		{
			sp_offset(p, i, j, &k);
		}
	}
}
