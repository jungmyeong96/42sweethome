/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@%tudent.42%eoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:23:38 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 17:39:33 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	//test format '%'
	
	printf("\n\n-----------1 option-------------\n\n");

	printf("test1[]:%%!\n");

	printf("test2[10]:%10%!\n");

	printf("test3[.20]:%.20%!\n");

	printf("test4[-10]:%-10%!\n");

	printf("test5[.-20]:%.-20%!\n"); //negative preci%ion == error

	printf("\n\n------------2 option------------\n\n");

	printf("test6[10.20]:%10.20%!\n");

	printf("test7[20.10]:%10.10%!\n");

	printf("test8[-10.20]:%-10.20%!\n");

	printf("test9[10.-20]:%10.-20%!\n"); //negative preci%ion == error

	printf("test10[20.-10]:%20.-10%!\n");//negative preci%ion == error

	printf("test11[-20.10]:%-20.10%!\n");

	printf("\n\n-----------wildcard-------------\n\n");

	printf("test12[10.*(20)]:%10.*%!\n",20);

	printf("test13[10.*(-20)%10.*%!\n",-20);

	printf("test14[20.*(10)]:%-10.*%!\n",10);

	printf("test15[20.*(-10)]:%-10.*%!\n",-10);

	printf("test16[*(10).20]:%*.20%!\n",10);

	printf("test17[*(-10).20]:%*.20%!\n",-10);

	printf("test18[*(20).10]:%*.10%!\n",20);

	printf("test19[*(-20).10]:%*.10%!\n",-20);

	printf("\n\n-------------apply to flag-----------\n\n");

	printf("test20[-010.20]:%-010.20%!\n");

	printf("test21[-020.10]:%-020.10%!\n");

	printf("test22[010.20]:%010.20%!\n");

	printf("test23[010.20]:%020.10%!\n");

	printf("\n\n-------------zero-----------\n\n");

	printf("test24[0.0]:%0.0%!\n");

	printf("test25[10.0]:%10.0%!\n");

	printf("test26[0.10]:%0.10%!\n");

	printf("\n\n-------------zero in wildcard-----------\n\n");

	printf("test27[*.]:%*.%!\n",0);

	printf("test28[*.-10]:%*.-10%!\n",0);

	printf("test29[10.*]:%10.*%!\n",0);

	printf("test30[-10.*]:%-10.*%!\n",0);

	printf("test31[*.*]:%*.*%!\n",0,0);

}
