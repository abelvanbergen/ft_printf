/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_octal.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:05:14 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 08:33:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_octal_fd(long long nb, int len, int fd)
{
	int		i;
	char	buf[22];

	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = len - 1;
	while (nb != 0)
	{
		if (nb % 8 < 10)
			buf[i] = '0' + nb % 8;
		else
			buf[i] = 87 + (nb % 8);
		nb /= 8;
		i--;
	}
	ft_putlstr_fd(buf, len, fd);
}

int	get_print_char_octal(t_flags *flags, long long nb, int len)
{
	int res;

	if (flags->precision == 1)
		flags->zero = 0;
	if (flags->precision == 1 && flags->prenumber == 0 &&
						nb == 0 && flags->hash == 0)
		return (0);
	if (flags->precision == 1 && flags->prenumber == 0 &&
					nb == 0 && flags->hash == 1)
		return (1);
	if (flags->prenumber > len)
		res = flags->prenumber;
	else
		res = len;
	return (res);
}

static void	print_octal_width(t_flags flags, int print_char, int len,
					unsigned long long nb)
{
	if (flags.zero == 1 && flags.precision == 0 && flags.dash == 0)
		ft_putlzero(flags.width - print_char);
	else
	{
		if (flags.hash == 1 && flags.prenumber <= len && nb != 0)
			ft_putlspace(flags.width - print_char - 1);
		else
			ft_putlspace(flags.width - print_char);
	}
}

int	print_octal(t_flags flags, unsigned long long nb)
{
	int len;
	int	print_char;

	len = nbr_spacecounter_figure_base_u(nb, 8);
	print_char = get_print_char_octal(&flags, nb, len);
	if (flags.width > print_char && flags.dash == 0)
		print_octal_width(flags, print_char, len, nb);
	if (print_char != 0)
	{
		if (flags.prenumber > len)
			ft_putlzero(flags.prenumber - len);
		else
		{
			if (flags.hash == 1 && (flags.zero == 0 ||
					flags.width <= print_char) && nb != 0)
				write(1, "0", 1);
		}
		ft_putnbr_octal_fd(nb, len, 1);
	}
	if (flags.width > print_char && flags.dash == 1)
		print_octal_width(flags, print_char, len, nb);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
