/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:43:02 by junghan           #+#    #+#             */
/*   Updated: 2021/01/21 13:26:39 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	printf("%d\n",1234);
	printf("%s\n","afadfnlk");
	printf("%%%%\n");

	ft_printf("something\n");
	return (0);
}
