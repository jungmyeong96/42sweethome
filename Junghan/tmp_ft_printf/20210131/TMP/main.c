/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:43:02 by junghan           #+#    #+#             */
/*   Updated: 2021/01/31 16:37:11 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{

	ft_printf("test1[*.*]:\n%-*.*u\n", 1, 4, 12);
	ft_printf("test2[c]:\n%c\n", 'a');
	ft_printf("t3 %d\n",ft_printf("test3[.*]:\n%.*d\n",67,5));
	ft_printf("t3 %d\n",ft_printf("test4[*.4]:\n%*.4i\n",-23,42));
	ft_printf("test5[-0*.*d]:\n%-0*.*d\n",-123,-23,20);
	ft_printf("test6[*s]:\n%*s\n",1,"12312312");
	ft_printf("test7[000*d]:\n%000*d\n",1,10);
	ft_printf("test8[d]:\n%d\n",1,10);
	ft_printf("(%%)(d)bada(s)(%%)**(s)**-d(%%)0*d (-12s)\n%%%dbada%s%%**%s**-d%%0*d%-12s0*@", 10, "bada", "string", "sssss d fs");
}