/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chg_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 23:33:27 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 23:50:07 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_chg_to_hex(unsigned int num, const char *spec)
{
	char	*hex;
	char	result[8];
	int		idx;

	ft_bzero(result, 8);
	if (*spec == 'x' || *spec == 'p')
		hex = "0123456789abcdef";
	else if (*spec == 'X')
		hex = "0123456789ABCDEF";
	idx = 8;
	while (idx > 0)
	{
		result[idx] = hex[num % 16];
		num = num / 16;
		idx--;
	}
	return (result);
}