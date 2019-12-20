/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_str.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:25:01 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/16 11:47:15 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_str_null(t_flags flags)
{
	char	*str0;
	int		strlen;
	int		print_char;

	str0 = "(null)";
	strlen = 6;
	if (flags.prenumber < strlen && flags.precision == 1)
		print_char = flags.prenumber;
	else
		print_char = strlen;
	if (flags.width > print_char && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - print_char);
		else
			ft_putlspace(flags.width - print_char);
	}
	ft_putlstr_fd(str0, print_char, 1);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}

int	print_str(t_flags flags, char *str)
{
	int strlen;
	int	print_char;

	if (str == 0)
		return (print_str_null(flags));
	strlen = ft_strlen(str);
	if (flags.prenumber < strlen && flags.precision == 1)
		print_char = flags.prenumber;
	else
		print_char = strlen;
	if (flags.width > print_char && flags.dash == 0)
	{
		if (flags.zero == 1)
			ft_putlzero(flags.width - print_char);
		else
			ft_putlspace(flags.width - print_char);
	}
	ft_putlstr_fd(str, print_char, 1);
	if (flags.width > print_char && flags.dash == 1)
		ft_putlspace(flags.width - print_char);
	if (flags.width > print_char)
		return (flags.width);
	return (print_char);
}
