/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:57:29 by junghan           #+#    #+#             */
/*   Updated: 2021/03/02 23:49:46 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*fin;
	char	*tmp;

	fin = NULL;
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == (char)c)
			fin = tmp;
		tmp++;
	}
	if (*tmp == (char)c)
		fin = tmp;
	return (fin);
}
