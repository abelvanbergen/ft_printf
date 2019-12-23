/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 12:59:28 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 16:32:08 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>
#include <stdio.h>
#include <locale.h>

int main(int ac, char **av)
{
	setlocale(LC_ALL, "en_US");
	int i;
	int res_real;
	int res_own;
	int iord;
	int x;
	int X;
	int u;
	int c;
	int s;
	int p;
	int basis;
	int procent;
	int test;

	i = 0;
	iord = 0;
	x = 0;
	X = 0;
	u = 0;
	c = 0;
	s = 0;
	p = 0;
	test = 0;
	basis = 0;
	procent = 0;
	if (ac == 1)
	{
		iord = 1;
		x  = 1;
		X = 1;
		u = 1;
		c = 1;
		s = 1;
		p = 1;
		basis = 1;
		procent = 0;
	}
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == 'i' || av[1][i] == 'd')
				iord = 1;
			else if (av[1][i] == 'x')
				x = 1;
			else if (av[1][i] == 'X')
				X = 1;
			else if (av[1][i] == 's')
				s = 1;
			else if (av[1][i] == 'c')
				c = 1;
			else if (av[1][i] == 'p')
				p = 1;
			else if (av[1][i] == 'u')
				u = 1;
			else if (av[1][i] == '%')
				procent = 1;
			else if (av[1][i] == 't')
				test = 1;
			i++;
		}
	}
	if (basis == 1)
	{
		printf("normal string\n--------------------------------------------------------\n");
		res_real = printf("real = lights will guide you home");
		printf("		res = %d\n", res_real - 7);
		res_own = ft_printf("own  = lights will guide you home");
		printf("		res = %d\n", res_own - 7);
		printf("\n");
		res_real = printf("real = And ignite your bones");
		printf("			res = %d\n", res_real - 7);
		res_own = ft_printf("own  = And ignite your bones");
		printf("			res = %d\n", res_own - 7);
		printf("\n");
		res_real = printf("real = And I will try to fix you");
		printf("		res = %d\n", res_real - 7);
		res_own = ft_printf("own  = And I will try to fix you");
		printf("		res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (c == 1)
	{
		printf("specifier c\n--------------------------------------------------------\n");
		res_real = printf("real = [%c]", 'a');
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%c]", 'a');
		printf("					res = %d\n", res_own - 7);
		printf("\n");
		res_real = printf("real = [%10c]", 'a');
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10c]", 'a');
		printf("				res = %d\n", res_own - 7);
		printf("\n");
		res_real = printf("real = [%-5c]", 'a');
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-5c]", 'a');
		printf("					res = %d\n", res_own - 7);
		printf("\n");
		res_real = printf("real = [%*c]", -5, 'a');
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%*c]", -5, 'a');
		printf("					res = %d\n", res_own - 7);
		res_real = printf("real = [%c]", '\t');
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%c]", '\t');
		printf("				res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (procent == 1)
	{
		printf("specifier %%\n--------------------------------------------------------\n");
		res_real = printf("real = [%%]");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%%]");
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10%]");
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10%]");
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-5%]");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-5%]");
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%*%]", -5);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%*%]", -5);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%*%%%%*%]", -5, 5);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%*%%%%*%]", -5, 5);
		printf("				res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (s == 1)
	{
		printf("specifier s\n--------------------------------------------------------\n");
		char	*str1 = "he";
		char	*str2 = 0;

		res_real = printf("real = [%s]", "abcde");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%s]", "abcde");
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10s]", "abcde");
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10s]", "abcde");
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10s]", "abcde");
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10s]", "abcde");
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%.2s]", "abcde");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.2s]", "abcde");
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%*.*s]", 2, 2, "abcde");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%*.*s]", 2, 2, "abcde");
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-*.*s]", -3, 7, "abcde");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-*.*s]", -3, 7, "abcde");
		printf("					res = %d\n", res_own - 7);
				printf("\n");
		res_real = printf("real = [%s]", str1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%s]", str1);
		printf("					res = %d\n", res_own - 7);
				printf("\n");
		res_real = printf("real = [%-*.*s]", -3, 7, str1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-*.*s]", -3, 7, str1);
		printf("					res = %d\n", res_own - 7);
				printf("\n");
		res_real = printf("real = [%s]", str2);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%s]", str2);
		printf("					res = %d\n", res_own - 7);
				printf("\n");
		res_real = printf("real = [%-*.*s]", 10, 3, str2);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-*.*s]", 10, 3, str2);
		printf("				res = %d\n", res_own - 7);
				printf("\n");
		res_real = printf("real = [%-----*.*s]", -3, 7, "done");
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-----*.*s]", -3, 7, "done");
		printf("					res = %d\n", res_own - 7);
		printf("========================================================\n\n\n");
	}
	if (iord == 1)
	{
		printf("specifier i & d\n--------------------------------------------------------\n");
		res_real = printf("real = [%i]", 1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%i]", 1);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%d]", 0);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%d]", 0);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%i]", 2147483647);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%i]", 2147483647);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%i]", -2147483648);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%i]", -2147483648);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10i]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10i]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.7i]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.7i]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%010i]", -12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%010i]", -12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10.7i]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10.7i]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10.7i]", -12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10.7i]", -12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%*.7i]", 10, -12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%*.7i]", 10, -12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%.*i]", -10, 12345);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.*i]", -10, 12345);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%---00--*.7i]", 10, 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%---00--*.7i]", 10, 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%06.8i]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%06.8i]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.i]", 0);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.i]", 0);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.i]", 10);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.i]", 10);
		printf("				res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (u == 1)
	{
		printf("specifier u\n--------------------------------------------------------\n");
		res_real = printf("real = [%u]", 1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%u]", 1);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%u]", 0);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%u]", 0);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%u]", 2147483647);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%u]", 2147483647);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%u]", 4294967295);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%u]", 4294967295);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10u]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10u]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.7u]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.7u]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10.7u]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10.7u]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%.*u]", -10, 12345);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.*u]", -10, 12345);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%---00--*.7u]", 10, 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%---00--*.7u]", 10, 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%06.8u]", 12345);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%06.8u]", 12345);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.u]", 0);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.u]", 0);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.u]", 10);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.u]", 10);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.u]", -5);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.u]", -5);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%lu]", 22337203685477);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%lu]", 22337203685477);
		printf("				res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (x == 1)
	{
		printf("specifier x\n--------------------------------------------------------\n");
		res_real = printf("real = [%x]", 1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%x]", 1);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%x]", 0);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%x]", 0);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%x]", 2147483647);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%x]", 2147483647);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%x]", 4294967295);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%x]", 4294967295);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10x]", 11259375);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10x]", 11259375);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.7x]", 11259375);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.7x]", 11259375);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10.7x]", 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10.7x]", 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%.*x]", -10, 11256099);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.*x]", -10, 11256099);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%---00--*.7x]", 10, 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%---00--*.7x]", 10, 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%06.8x]", 4550127);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%06.8x]", 4550127);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.x]", 0);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.x]", 0);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.x]", 10);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.x]", 10);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.x]", -5);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.x]", -5);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%llx]", 18446744073709551614);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%llx]", 18446744073709551614);
		printf("				res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (X == 1)
	{
		printf("specifier X\n--------------------------------------------------------\n");
		res_real = printf("real = [%X]", 1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%X]", 1);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%X]", 0);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%X]", 0);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%X]", 2147483647);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%X]", 2147483647);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%X]", 4294967295);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%X]", 4294967295);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10X]", 11259375);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10X]", 11259375);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.7X]", 11259375);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.7X]", 11259375);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10.7X]", 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10.7X]", 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%.*X]", -10, 11256099);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.*X]", -10, 11256099);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%---00--*.7X]", 10, 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%---00--*.7X]", 10, 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%06.8X]", 4550127);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%06.8X]", 4550127);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.X]", 0);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.X]", 0);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.X]", 10);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.X]", 10);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.X]", -5);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.X]", -5);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		printf("========================================================\n\n\n\n\n");
	}
	if (p == 1)
	{
		printf("specifier p\n--------------------------------------------------------\n");
		res_real = printf("real = [%p]", 1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%p]", 1);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%p]", 0);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%p]", 0);
		printf("					res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%p]", 2147483647);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%p]", 2147483647);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%p]", 4294967295);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%p]", 4294967295);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10p]", 11259375);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10p]", 11259375);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.7p]", 11259375);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.7p]", 11259375);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%-10.7p]", 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%-10.7p]", 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%.*p]", -10, 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.*p]", -10, 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%---00--*.7p]", 10, 11256099);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%---00--*.7p]", 10, 11256099);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%06.8p]", 4550127);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%06.8p]", 4550127);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.p]", 0);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.p]", 0);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.p]", 10);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.p]", 10);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.p]", -5);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.p]", -5);
		printf("				res = %d\n", res_own - 7);
			printf("\n");
		res_real = printf("real = [%10.p]", 0);
		printf("				res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%10.p]", 0);
		printf("				res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	if (test == 1)
	{
	printf("losse test\n--------------------------------------------------------\n");
		// res_real = printf("real = [%010f]", 1.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%010f]", 1.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%010F]", 1.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%010F]", 1.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 		printf("\n");
		// res_real = printf("real = [%-10f]", 1.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%-10f]", 1.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 		printf("\n");
		// res_real = printf("real = [%-10F]", 1.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%-10F]", 1.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 		printf("\n");
		// res_real = printf("real = [%-10F]", 0.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%-10F]", 0.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%-+10F]", 0.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%-+10F]", 0.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%-+10F]", 1.0/0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%-+010F]", 1.0/0.0);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%-10F]", -0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%-10F]", -0.0);
		// printf("					res = %d\n", res_own - 7);
		// 		printf("\n");
		// 	res_real = printf("real = [%.0f]", 4.50);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%.0f]", 4.50);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%.0f]", -2.5);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%.0f]", -2.5);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%.0f]", -3.5);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%.0f]", -3.5);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%.0f]", 3.5);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%.0f]",  3.5);
		// printf("					res = %d\n", res_own - 7);
		// 	printf("\n");
		// res_real = printf("real = [%.10f]", 0.0);
		// printf("					res = %d\n", res_real - 7);
		// res_own = ft_printf("own  = [%.10f]",  0.0);
		// printf("					res = %d\n", res_own - 7);
		// 		printf("\n");
		res_real = printf("real = [%.8e]", 1234567890123456.1);
		printf("					res = %d\n", res_real - 7);
		res_own = ft_printf("own  = [%.8e]", 1234567890123456.1);
		printf("					res = %d\n", res_own - 7);
		printf("========================================================\n\n\n\n\n");
	}
	return (0);
}
