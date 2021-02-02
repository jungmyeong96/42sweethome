/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_ID.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@dtudent.42deoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   dreated: 2021/01/22 13:23:38 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 19:44:33 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	//test format 'd'
	
	printf("\n\n-----------1 option-------------\n\n");

	printf("test1[d]:%d!\n",123);

	printf("test2[10d]:%10d!\n",123);

	printf("test3[.20]:%.20d!\n",123);

	printf("test4[-10]:%-10d!\n",123);

	printf("test5[.-20]:%.-20d!\n",123); //negative precision

	printf("\n\n------------2 option------------\n\n");

	printf("test6[10.20]:%10.20d!\n",123);

	printf("test7[20.10]:%10.10d!\n",123);

	printf("test8[-10.20]:%-10.20d!\n",123);

	printf("test9[10.-20]:%10.-20d!\n",123); //as above

	printf("test10[20.-10]:%20.-10d!\n",123);//as above

	printf("test11[-20.10]:%-20.10d!\n",123);

	printf("\n\n-----------wilddard-------------\n\n");

	printf("test12[10.*(20)]:%10.*d!\n",20,123);

	printf("test13[10.*(-20)%10.*d!\n",-20,123);

	printf("test14[20.*(10)]:%-10.*d!\n",10,123);

	printf("test15[20.*(-10)]:%-10.*d!\n",-10,123);

	printf("test16[*(10).20]:%*.20d!\n",10,123);

	printf("test17[*(-10).20]:%*.20d!\n",-10,123);

	printf("test18[*(20).10]:%*.10d!\n",20,123);

	printf("test19[*(-20).10]:%*.10d!\n",-20,123);

	printf("\n\n-------------apply to flag-----------\n\n");

	printf("test20[-010.20]:%-010.20d!\n",123);//double flag

	printf("test21[-020.10]:%-020.10d!\n",123);//double flag

	printf("test22[010.20]:%010.20d!\n",123);

	printf("test23[010.20]:%020.10d!\n",123);

	printf("\n\n-------------zero-----------\n\n");

	printf("testz1[0]:%0d!\n",123);

	printf("testz2[0]:%.0d!\n", 123);

	printf("test24[0.0]:%0.0d!\n",123);

	printf("test25[10.0]:%10.0d!\n",123);

	printf("test26[0.10]:%0.10d!\n",123);

	printf("\n\n-------------zero in wilddard-----------\n\n");

	printf("test27[*.10]:%*.10d!\n",0, 123);

	printf("test28[*.]:%*.d!\n",0, 123);

	printf("test29[10.*]:%10.*d!\n",0, 123);

	printf("test30[-10.*]:%-10.*d!\n",0, 123);

	printf("test31[*.*]:%*.*d!\n",0,0, 123);


}
