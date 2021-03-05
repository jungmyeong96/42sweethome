/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 06:55:14 by daekim            #+#    #+#             */
/*   Updated: 2021/03/06 01:16:03 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		buf_mal(t_info *p)
{
	int		i;

	if (!(p->buf = (int **)ft_calloc(p->data.win_h, sizeof(int *))))
		putstr_err("Error : buf allocate fail!");
	i = 0;
	while (i < p->data.win_h)
	{
		if (!(p->buf[i] = (int *)ft_calloc(p->data.win_w, sizeof(int))))
			putstr_err("Error : buf[i] allocate fail!");
		i++;
	}
	if (!(p->sp.zbuf = (double *)ft_calloc(p->data.win_w, sizeof(double))))
		putstr_err("Error : zbuf allocate fail!");
}

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
	if (ft_strncmp(form, s2, s2_len) == 0)
		return (1);
	return (0);
}

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

void		putstr_err(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(0);
}
