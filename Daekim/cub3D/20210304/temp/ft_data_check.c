/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 00:28:09 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 20:37:45 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			check_char(int c)
{
	if (!(c == '0' || c == '1' || c == '2' ||
		   c == 'N' || c == 'E' || c == 'W' || c == 'S'))
		putstr_err("Error : map invalid");
}
