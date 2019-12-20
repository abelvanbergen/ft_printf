/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_char.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:22:13 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/14 13:55:56 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_char(t_flags flags, char c)
{
	if (flags.width > 1 && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - 1);
		else
			ft_putlspace(flags.width - 1);
	}
	write(1, &c, 1);
	if (flags.width > 1 && flags.dash == 1)
		ft_putlspace(flags.width - 1);
	if (flags.width > 1)
		return (flags.width);
	return (1);
}
