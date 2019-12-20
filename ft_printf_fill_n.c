/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_fill_n.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:54:29 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/20 15:33:15 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	fill_n_int(va_list ap, int count)
{
	int *n_int;

	n_int = va_arg(ap, int *);
	*n_int = count;
}

void	fill_n_long(va_list ap, int count)
{
	long *n_long;

	n_long = va_arg(ap, long *);
	*n_long = count;
}

void	fill_n_longlong(va_list ap, int count)
{
	long long *n_longlong;

	n_longlong = va_arg(ap, long long *);
	*n_longlong = count;
}

void	fill_n_short(va_list ap, int count)
{
	short *n_short;

	n_short = va_arg(ap, short *);
	*n_short = count;
}

void	fill_n_shortshort(va_list ap, int count)
{
	signed char *n_shortshort;

	n_shortshort = va_arg(ap, signed char *);
	*n_shortshort = count;
}
