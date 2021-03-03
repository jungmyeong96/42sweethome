/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:27:41 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 01:11:31 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		sort_sp(double *tap1, int *tap2, int size)
{
	int		a;
	double	temp1;
	int		temp2;

	a = -1;
	while (++a < size - 1)
		if (tap1[a] > tap1[a + 1])
		{
			temp1 = tap1[a];
			tap1[a] = tap1[a + 1];
			tap1[a + 1] = temp1;
			temp2 = tap2[a];
			tap2[a] = tap2[a + 1];
			tap2[a + 1] = temp2;
			sort_sp(tap1, tap2, size);
		}
}
