/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_S.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:23:38 by junghan           #+#    #+#             */
/*   Updated: 2021/01/28 17:16:15 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	//test format 'S'
	
	printf("\n\n-----------1 option-------------\n\n");

	printf("test1[S]:%s!\n","hahaha");

	printf("test2[10s]:%10s!\n","hahaha");

	printf("test3[.20]:%.20s!\n","hahaha");

	printf("test4[-10]:%-10s!\n","hahaha");

	printf("test5[.-20]:%.-20s!\n","hahaha"); //negative precision == error

	printf("\n\n------------2 option------------\n\n");

	printf("test6[10.20]:%10.20s!\n","hahaha");

	printf("test7[20.10]:%10.10s!\n","hahaha");

	printf("test8[-10.20]:%-10.20s!\n","hahaha");

	printf("test9[10.-20]:%10.-20s!\n","hahaha"); //negative precision == error

	printf("test10[20.-10]:%20.-10s!\n","hahaha");//negative precision == error

	printf("test11[-20.10]:%-20.10s!\n","hahaha");

	printf("\n\n-----------wildcard-------------\n\n");

	printf("test12[10.*(20)]:%10.*s!\n",20,"hahaha");

	printf("test13[10.*(-20)%10.*s!\n",-20,"hahaha");

	printf("test14[20.*(10)]:%-10.*s!\n",10,"hahaha");

	printf("test15[20.*(-10)]:%-10.*s!\n",-10,"hahaha");

	printf("test16[*(10).20]:%*.20s!\n",10,"hahaha");

	printf("test17[*(-10).20]:%*.20s!\n",-10,"hahaha");

	printf("test18[*(20).10]:%*.10s!\n",20,"hahaha");

	printf("test19[*(-20).10]:%*.10s!\n",-20,"hahaha");

	printf("\n\n-------------apply to flag-----------\n\n");

	printf("test20[-010.20]:%-010.20s!\n","hahaha");//'s' can't use '0'flag

	printf("test21[-020.10]:%-020.10s!\n","hahaha");//'-' and '0' can't be used together except in the case '%' 

	printf("test22[010.20]:%010.20s!\n","hahaha");//as above '0'

	printf("test23[010.20]:%020.10s!\n","hahaha");//as above '0'


	printf("\n\n-------------zero-----------\n\n");

	printf("test--[0]:%0s!\n","hahaha");

	printf("test24[0.0]:%0.0s!\n","hahaha");

	printf("test25[10.0]:%10.0s!\n","hahaha");

	printf("test26[0.10]:%0.10s!\n","hahaha");

	printf("\n\n-------------zero in wildcard-----------\n\n");

	printf("test27[*.10]:%*.10s!\n",0,"hahaha");

	printf("test28[*.0]:%*.s!\n",0,"hahaha");

	printf("test29[10.*]:%10.*s!\n",0,"hahaha");

	printf("test30[-10.*]:%-10.*s!\n",0,"hahaha");

	printf("test31[*.*]:%*.*s!\n",0,0,"hahaha");
}
