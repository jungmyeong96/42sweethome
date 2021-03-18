/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 06:55:14 by daekim            #+#    #+#             */
/*   Updated: 2021/03/09 01:45:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		buf_mal(t_info *p)
{
	int		i;

	if (!(p->buf = (int **)ft_calloc(p->data.win_h,
					sizeof(int *))))
		putstr_err("Error : buf allocate fail!\n");
	i = -1;
	while (++i < p->data.win_h)
		if (!(p->buf[i] = (int *)ft_calloc(p->data.win_w,
						sizeof(int))))
			putstr_err("Error : buf[i] allocate fail!\n");
	if (!(p->sp.zbuf = (double *)ft_calloc(p->data.win_w, sizeof(double))))
		putstr_err("Error : zbuf allocate fail!\n");
	if (!(p->minimap = (int **)ft_calloc(p->data.win_h / 5,
					sizeof(int *))))
		putstr_err("Error : minimap first error allocate fail!\n");
	i = -1;
	while (++i < p->data.win_h / 5)
		if (!(p->minimap[i] = (int *)ft_calloc(p->data.win_w / 4,
						sizeof(int))))
			putstr_err("Error : minimap second allocate fail!\n");
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

int			is_space(char *d, t_info *p)
{
	int		i;

	i = -1;
	while (d[++i] && p->check_ele[6] < 1)
	{
		if ((d[i] >= 9 && d[i] <= 13) || d[i] == ' ')
			continue ;
		return (0);
	}
	return (1);
}
