/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putlfiller.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:23:39 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/13 11:08:40 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putlspace(int len)
{
	char *buf;

	buf = "                    ";
	while (len >= 20)
	{
		ft_putlstr_fd(buf, 20, 1);
		len -= 20;
	}
	ft_putlstr_fd(buf, len, 1);
}

void	ft_putlzero(int len)
{
	char *buf;

	buf = "00000000000000000000";
	while (len >= 20)
	{
		ft_putlstr_fd(buf, 20, 1);
		len -= 20;
	}
	ft_putlstr_fd(buf, len, 1);
}
