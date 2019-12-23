/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils3.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 15:53:27 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 15:49:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	get_figure(long long nb)
{
	if (nb >= 0)
		return ('0' + nb % 10);
	else
		return ('0' - (nb % 10));
}

void	put_float_after(t_flags flags, long long nb)
{
	int		i;
	int		len;
	char	buf[30];

	i = flags.prenumber - 1;
	len = nbr_spacecounter_figure_base(nb, 10);
	if (nb == 0)
	{
		buf[i] = '0';
		i--;
	}
	while (nb != 0)
	{
		buf[i] = get_figure(nb);
		nb /= 10;
		i--;
	}
	while (flags.prenumber > len)
	{
		buf[i] = '0';
		len++;
		i--;
	}
	ft_putlstr_fd(buf, len, 1);
}
