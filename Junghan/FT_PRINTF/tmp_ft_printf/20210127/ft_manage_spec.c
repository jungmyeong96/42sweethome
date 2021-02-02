/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:39:08 by junghan           #+#    #+#             */
/*   Updated: 2021/01/27 17:02:10 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_manage_spec(va_list ap, const char *spec)
{
	if (*spec == '%')
		ft_putchar_fd(1, '%');
	else if (*spec == 'c')

	return (spec);
}
