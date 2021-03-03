/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 05:46:03 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 04:25:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		free_dou(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = 0;
		i++;
	}
	free(str);
	str = 0;
}
