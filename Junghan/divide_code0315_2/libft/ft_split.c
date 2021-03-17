/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:53:08 by junghan           #+#    #+#             */
/*   Updated: 2021/03/05 09:24:25 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_getlen(char *s, char c, int *start, int *end)
{
	*start = *end;
	while (s[*start] == c)
	{
		(*start)++;
	}
	*end = *start;
	while (s[*end] != '\0' && s[*end] != c)
	{
		(*end)++;
	}
}

static void	ft_setword(char *s, char *result, int start, int end)
{
	int	i;

	if (start < end)
	{
		i = 0;
		while (start < end)
		{
			result[i] = s[start];
			i++;
			start++;
		}
		result[i] = '\0';
	}
}

static int	ft_countword(char *s, char c)
{
	int	i;
	int	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	if (i == 0 && s[i] == c)
		i++;
	else if (i == 0 && s[i] != c)
	{
		i++;
		count++;
	}
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_freearr(char **forfree)
{
	int	i;

	i = 0;
	while (forfree[i])
	{
		free(forfree[i]);
		i++;
	}
	free(forfree);
	return (NULL);
}

char		**ft_split(char *s, char c)
{
	char	**result;
	int		count;
	int		start;
	int		end;
	int		i;

	end = 0;
	if (!s)
		return (0);
	count = ft_countword(s, c);
	if (!(result = (char **)ft_calloc(count + 1, sizeof(char *))))
		return (0);
	i = 0;
	while (i < count)
	{
		ft_getlen(s, c, &start, &end);
		if (!(result[i] = (char *)ft_calloc(end - start + 1, sizeof(char))))
			return (ft_freearr(result));
		ft_setword(s, result[i], start, end);
		i++;
	}
	return (result);
}
