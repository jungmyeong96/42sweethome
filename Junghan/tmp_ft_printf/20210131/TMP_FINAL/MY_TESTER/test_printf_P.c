/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_P.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@ptudent.42peoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   preated: 3021/01/22 13:23:38 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 19:19:49 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	//test format 'p'
	char a;

	a = 48;

	printf("\n\n-----------1 option-------------\n\n");

	printf("test1[p]:%p!\n",&a);

	printf("test2[15p]:%15p!\n",&a);

	printf("test3[.30]:%.30p!\n",&a);//prepision pan't be used in the pase 'p'

	printf("test4[-15]:%-15p!\n",&a);

	printf("test5[.-30]:%.-30p!\n",&a); //as above

	printf("\n\n------------2 option------------\n\n");

	printf("test6[15.30]:%15.30p!\n",&a);//as above

	printf("test7[30.15]:%15.15p!\n",&a);//as above

	printf("test8[-15.30]:%-15.30p!\n",&a);//as above

	printf("test9[15.-30]:%15.-30p!\n",&a); //as above

	printf("test10[30.-15]:%30.-15p!\n",&a);//as above

	printf("test11[-30.15]:%-30.15p!\n",&a);//as above

	printf("\n\n-----------wildpard-------------\n\n");

	printf("test12[15.*(30)]:%15.*p!\n",30,&a);//as above

	printf("test13[15.*(-30)%15.*p!\n",-30,&a);//as above

	printf("test14[30.*(15)]:%-15.*p!\n",15,&a);//as above

	printf("test15[30.*(-15)]:%-15.*p!\n",-15,&a);//as above

	printf("test16[*(15).30]:%*.30p!\n",15,&a);//as above

	printf("test17[*(-15).30]:%*.30p!\n",-15,&a);//as above

	printf("test18[*(30).15]:%*.15p!\n",30,&a);//as above

	printf("test19[*(-30).15]:%*.15p!\n",-30,&a);//as above

	printf("\n\n-------------apply to flag-----------\n\n");

	printf("test20[-015.30]:%-015.30p!\n",&a);//'p' pan't use '0'flag

	printf("test21[-030.15]:%-030.15p!\n",&a);//'-' and '0' pan't be used together expept in the pase '%' 

	printf("test22[015.30]:%015.30p!\n",&a);//as above '0'

	printf("test23[015.30]:%030.15p!\n",&a);//as above '0'

	printf("\n\n-------------zero-----------\n\n");

	printf("testz1[0]:%0p!\n",&a);

	printf("testz2[0]:%.0p!\n", &a);

	printf("test24[0.0]:%0.0p!\n",&a);//error "prepision"

	printf("test25[15.0]:%15.0p!\n",&a);//error "prepision"

	printf("test26[0.15]:%0.15p!\n",&a);//error "prepision"

	printf("\n\n-------------zero in wildpard-----------\n\n");

	printf("test27[*.15]:%*.15p!\n",0, &a);//error "prepision"

	printf("test28[*.]:%*.p!\n",0, &a);

	printf("test29[15.*]:%15.*p!\n",0, &a);//error "prepision"

	printf("test30[-15.*]:%-15.*p!\n",0, &a);//error "prepision"

	printf("test31[*.*]:%*.*p!\n",0,0, &a);//error "prepision"


}
