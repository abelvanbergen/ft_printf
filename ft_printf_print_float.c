/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_float.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:29:55 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/19 16:23:23 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_float_length(t_flags flags, t_float *floatinfo)
{
	floatinfo->length = floatinfo->nb_before_length + flags.prenumber;
	if (!(flags.precision == 1 && flags.prenumber == 0 && flags.hash == 0))
		floatinfo->length++;
	if (floatinfo->neg == 1 || flags.plus == 1 || flags.space == 1)
		floatinfo->length++;
	if (flags.apostrophe == 1)
	{
		floatinfo->length += (floatinfo->nb_before_length - 1) / 3;
		floatinfo->nb_before_length += (floatinfo->nb_before_length - 1) / 3;
	}
}

void	get_floatinfo(t_flags flags, t_float *floatinfo, double nb)
{
	int				i;
	long long		res;

	i = 0;
	res = 10;
	floatinfo->nb_before = nb;
	floatinfo->neg = floatinfo->nb_before < 0 ? 1 : 0;
	floatinfo->nb_before_length =
				nbr_spacecounter_figure_base(floatinfo->nb_before, 10);
	nb -= floatinfo->nb_before;
	res = tentothepower(flags.prenumber);
	floatinfo->nb_after = nb * res;
	if (floatinfo->nb_after % 10 >= 5)
		floatinfo->nb_after += 10 - (floatinfo->nb_after % 10);
	floatinfo->nb_after /= 10;
	if (nbr_spacecounter_figure_base(floatinfo->nb_after, 10) >
				flags.prenumber && floatinfo->nb_after != 0)
	{
		floatinfo->nb_after = 0;
		floatinfo->nb_before++;
	}
	get_float_length(flags, floatinfo);
}

void	put_float_before(t_flags flags, long long nb, int len)
{
	int		i;
	int		count;
	char	buf[26];

	i = len - 1;
	if (nb == 0)
		buf[i] = '0';
	count = 1;
	while (nb != 0)
	{
		if ((count) % 4 == 0 && flags.apostrophe == 1)
			buf[i] = ',';
		else
		{
			buf[i] = get_figure(nb);
			nb /= 10;
		}
		i--;
		count++;
	}
	ft_putlstr_fd(buf, len, 1);
}

void	print_float_width_front(t_flags flags, t_float floatinfo)
{
	if (flags.zero == 1)
	{
		ft_print_sign(flags, floatinfo.neg);
		ft_putlzero(flags.width - floatinfo.length);
	}
	else
	{
		ft_putlspace(flags.width - floatinfo.length);
	}
}

int	print_float(t_flags flags, double nb)
{
	t_float floatinfo;

	setprecisionfloat(&flags);
	setfloatinfozero(&floatinfo);
	get_floatinfo(flags, &floatinfo, nb);
	if (flags.width > floatinfo.length && flags.dash == 0)
		print_float_width_front(flags, floatinfo);
	put_float_before(flags, floatinfo.nb_before, floatinfo.nb_before_length);
	if (!(flags.precision == 1 && flags.prenumber == 0 && flags.hash == 0))
		write(1, ".", 1);
	if (flags.prenumber != 0)
		put_float_after(flags, floatinfo.nb_after);
	if (flags.width > floatinfo.length && flags.dash == 1)
		ft_putlspace(flags.width - floatinfo.length);
	if (flags.width > floatinfo.length)
		return (flags.width);
	return (floatinfo.length);
}
