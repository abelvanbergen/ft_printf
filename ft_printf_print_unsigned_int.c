/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_unsigned_int.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:42:50 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/16 13:36:30 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr_unsigned_int(unsigned int nb,
										int len, int apostrophe, int fd)
{
	int		i;
	int		count;
	char	buf[13];

	i = len - 1;
	if (nb == 0)
		buf[i] = '0';
	count = 1;
	while (nb != 0)
	{
		if ((count) % 4 == 0 && apostrophe == 1)
			buf[i] = ',';
		else
		{
			buf[i] = '0' + nb % 10;
			nb /= 10;
		}
		i--;
	}
	ft_putlstr_fd(buf, len, fd);
}

int		get_print_char_un(t_flags flags, int nb, int len)
{
	int res;

	if (flags.precision == 1 && flags.prenumber == 0 && nb == 0)
		return (0);
	if (flags.prenumber > len)
		res = flags.prenumber;
	else
		res = len;
	if (flags.apostrophe == 1)
		res += (len - 1) / 3;
	return (res);
}

void	print_un_width_front(t_flags flags, int print_char)
{
	if (flags.zero == 1 && flags.prenumber == 0)
		ft_putlzero(flags.width - print_char);
	else
		ft_putlspace(flags.width - print_char);
}

int			print_unsigned_int(t_flags flags, unsigned int nb)
{
	int len;
	int print_char;

	len = nbr_spacecounter_figure_base(nb, 10);
	print_char = get_print_char_un(flags, nb, len);
	if (flags.width > print_char && flags.dash == 0)
		print_un_width_front(flags, print_char);
	if (print_char != 0)
	{
		if (flags.prenumber > len)
			ft_putlzero(flags.prenumber - len);
		if (flags.apostrophe == 1)
			ft_putnbr_unsigned_int(nb, len + (len - 1) / 3,
										flags.apostrophe, 1);
		else
			ft_putnbr_unsigned_int(nb, len, flags.apostrophe, 1);
	}
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
