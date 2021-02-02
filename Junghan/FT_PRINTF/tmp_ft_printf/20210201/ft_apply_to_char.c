/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:10:07 by junghan           #+#    #+#             */
/*   Updated: 2021/02/01 20:59:13 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_apply_to_percent(const char *spec, t_info info, int *result)
{
	int				len;

	if (info.p_num < 0)
		return (0);
	len = 1;
	*result += ft_print_char(spec, "%", info, len);
	return (1);
}

int		ft_apply_to_char(va_list *ap, const char *spec, t_info info, int *result)
{
	char			c;
	int				len;

	c = va_arg(*ap, int);
	if ((info.p_existence == DOTNUM) || (info.f_zero == YES))
		return (0);
	len = 1;
	*result += ft_print_char(spec, &c, info, len);
	return (1);
}

int		ft_apply_to_str(va_list *ap, const char *spec, t_info info, int *result)
{
	char			*str;
	int				len;

	if ((str = va_arg(*ap, char *)) == NULL)
		str = "(null)";
	if (info.f_zero == YES || (info.p_existence == DOTNUM && info.p_num < 0
				&& info.p_asterisk == NO))
		return (0);
	if ((info.p_existence == DOTNUM && info.p_num == 0)
			|| info.p_existence == ONLYDOT)
	{
		(*result) += info.w_num;
		while (info.w_num--)
			write(1, " ", sizeof(char));
		return (1);
	}
	len = ft_strlen(str);
	if (info.p_existence == DOTNUM && info.p_num > 0 && info.p_num < len)
		len = info.p_num;
	*result += ft_print_char(spec, str, info, len);
	return (1);
}

int		ft_apply_to_pointer(va_list *ap, const char *spec, t_info info, int *result)
{
	void			*ptr;
	char			*hex_ptr;
	char			*ox_hex;
	unsigned int	tmp;

	ptr = va_arg(*ap, void *);
	if ((info.p_existence == DOTNUM) || (info.f_zero == YES))
		return (0);
	tmp = (unsigned int)ptr;
	if (!(hex_ptr = ft_chg_to_hex(tmp, spec)))
		return (0);
	ox_hex = ft_strjoin("0x", hex_ptr);
	free(hex_ptr);
	hex_ptr = 0;
	tmp = ft_strlen(ox_hex);
	*result += (ft_print_char(spec, ox_hex, info, tmp));
	free(ox_hex);
	hex_ptr = 0;
	return (1);
}
