/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_C.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@ctudent.42ceoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:23:38 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 19:28:07 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	//test format 'c'
	
	printf("\n\n-----------1 option-------------\n\n");

	printf("test1[c]:%c!\n",'a');

	printf("test2[10c]:%10c!\n",'a');

	printf("test3[.20]:%.20c!\n",'a');//precision can't be used in the case 'C'

	printf("test4[-10]:%-10c!\n",'a');

	printf("test5[.-20]:%.-20c!\n",'a'); //as above

	printf("\n\n------------2 option------------\n\n");

	printf("test6[10.20]:%10.20c!\n",'a');//as above

	printf("test7[20.10]:%10.10c!\n",'a');//as above

	printf("test8[-10.20]:%-10.20c!\n",'a');//as above

	printf("test9[10.-20]:%10.-20c!\n",'a'); //as above

	printf("test10[20.-10]:%20.-10c!\n",'a');//as above

	printf("test11[-20.10]:%-20.10c!\n",'a');//as above

	printf("\n\n-----------wildcard-------------\n\n");

	printf("test12[10.*(20)]:%10.*c!\n",20,'a');//as above

	printf("test13[10.*(-20)%10.*c!\n",-20,'a');//as above

	printf("test14[20.*(10)]:%-10.*c!\n",10,'a');//as above

	printf("test15[20.*(-10)]:%-10.*c!\n",-10,'a');//as above

	printf("test16[*(10).20]:%*.20c!\n",10,'a');//as above

	printf("test17[*(-10).20]:%*.20c!\n",-10,'a');//as above

	printf("test18[*(20).10]:%*.10c!\n",20,'a');//as above

	printf("test19[*(-20).10]:%*.10c!\n",-20,'a');//as above

	printf("\n\n-------------apply to flag-----------\n\n");

	printf("test20[-010.20]:%-010.20c!\n",'a');//'c' can't use '0'flag

	printf("test21[-020.10]:%-020.10c!\n",'a');//'-' and '0' can't be used together except in the case '%' 

	printf("test22[010.20]:%010.20c!\n",'a');//as above '0'

	printf("test23[010.20]:%020.10c!\n",'a');//as above '0'

	printf("\n\n-------------zero-----------\n\n");

	printf("testz1[0]:%0c!\n",'a');

	printf("testz2[0]:%.0c!\n", 'a');

	printf("test24[0.0]:%0.0c!\n",'a');//error "precision"

	printf("test25[10.0]:%10.0c!\n",'a');//error "precision"

	printf("test26[0.10]:%0.10c!\n",'a');//error "precision"

	printf("\n\n-------------zero in wildcard-----------\n\n");

	printf("test27[*.10]:%*.10c!\n",0, 'a');//error "precision"

	printf("test28[*.]:%*.c!\n",0, 'a');//error "precision"

	printf("test29[10.*]:%10.*c!\n",0, 'a');//error "precision"

	printf("test30[-10.*]:%-10.*c!\n",0, 'a');//error "precision"

	printf("test31[*.*]:%*.*c!\n",0,0, 'a');//error "precision"


}
