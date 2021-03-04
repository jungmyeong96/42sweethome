/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 06:55:14 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 04:24:31 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			format(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*form;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len <= s2_len)
		return (0);
	form = s1 + s1_len - s2_len;
	if (ft_strncmp(s1, s2, s2_len) == 0)
		return (1);
	return (0);
}
