/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_e.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 10:44:26 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 17:13:32 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_e_length(t_flags flags, t_float *floatinfo)
{
	floatinfo->length = floatinfo->nb_before_length +
				floatinfo->nb_after_length + 4;
	if (!(flags.precision == 1 && flags.prenumber == 0 && flags.hash == 0))
		floatinfo->length++;
	if (floatinfo->neg == 1 || flags.plus == 1 || flags.space == 1)
		floatinfo->length++;
}

void	get_floatinfo_e(t_flags flags, t_float *floatinfo, double nb)
{
	long long	res;

	floatinfo->nb_before = nb;
	floatinfo->neg = nb < 0 ? 1 : 0;
	nb -= floatinfo->nb_before;
	if (floatinfo->nb_before == 0)
		floatinfo->nb_before_length = 0;
	else
		floatinfo->nb_before_length =
			nbr_spacecounter_figure_base(floatinfo->nb_before, 10);
	floatinfo->nb_after_length = flags.prenumber - floatinfo->nb_before_length + 1;
	if (floatinfo->nb_before == 0)
	{
		floatinfo->nb_zero_sign = 1;
		while (floatinfo->nb_before == 0)
		{
			nb *= 10;
			floatinfo->power++;
			floatinfo->nb_before = nb;
		}
		floatinfo->nb_after = (nb - floatinfo->nb_before) *
				tentothepower(flags.prenumber);
	}
	else
	{
		if (floatinfo->nb_after_length + 1 < 0)
			res = 1;
		else if (floatinfo->nb_after_length == -1)
			res = 10;
		else
			res = tentothepower(floatinfo->nb_after_length);
		floatinfo->nb_after = nb * res;
		while (floatinfo->nb_before > 9 || floatinfo->nb_before < -9)
		{
			floatinfo->nb_after += (floatinfo->nb_before % 10) * res;
			res *= 10;
			floatinfo->nb_before /= 10;
			floatinfo->power++;
		}
	}
	if (floatinfo->nb_after % 10 >= 5)
		floatinfo->nb_after += 10 - (floatinfo->nb_after % 10);
	floatinfo->nb_after /= 10;
	if (nbr_spacecounter_figure_base(floatinfo->nb_after, 10) >
			flags.prenumber && floatinfo->nb_after != 0 && flags.prenumber != 0)
	{
		floatinfo->nb_after = 0;
		floatinfo->nb_before++;
	}
	get_e_length(flags, floatinfo);
}

void	put_e_before(t_flags flags, int neg, int nb)
{
	char	buf[3];
	int		i;

	i = 0;
	if (neg == 1 || flags.plus == 1 || flags.space == 1)
	{
		if (neg == 1)
			buf[i] = '-';
		else if (flags.plus == 1)
			buf[i] = '+';
		else
			buf[i] = ' ';
		i++;
	}
	if (nb < 0)
		buf[i] = '0' - (nb % 10);
	else
		buf[i] = '0' + nb % 10;
	i++;
	if (!(flags.precision == 1 && flags.prenumber == 0 && flags.hash == 0))
	{
		buf[i] = '.';
		i++;
	}
	ft_putlstr_fd(buf, i, 1);
}

void	print_e_sign(t_float floatinfo, char cap)
{
	char	buf[4];

	buf[0] = cap;
	if (floatinfo.nb_zero_sign == 1)
		buf[1] = '-';
	else
		buf[1] = '+';
	buf[3] = '0' + floatinfo.power % 10;
	if (floatinfo.power > 9)
		buf[2] = '0' + (floatinfo.power / 10) % 10;
	else
		buf[2] = '0';
	ft_putlstr_fd(buf, 4, 1);
}

int		print_e(t_flags flags, double nb, char cap)
{
	t_float floatinfo;

	setprecisionfloat(&flags);
	setfloatinfozero(&floatinfo);
	get_floatinfo_e(flags, &floatinfo, nb);
	if (flags.width > floatinfo.length && flags.dash == 0)
	{
		if (flags.zero == 1)
		{
			ft_print_sign(flags, floatinfo.neg);
			ft_putlzero(flags.width - floatinfo.length);
		}
		else
			ft_putlspace(flags.width - floatinfo.length);
	}
	if (flags.zero == 0 || flags.width <= floatinfo.length)
		ft_print_sign(flags, floatinfo.neg);
	put_e_before(flags, floatinfo.neg, floatinfo.nb_before);
	if (flags.prenumber != 0)
		put_float_after(flags, floatinfo.nb_after);
	print_e_sign(floatinfo, cap);
	if (flags.width > floatinfo.length && flags.dash == 1)
		ft_putlspace(flags.width - floatinfo.length);
	if (flags.width > floatinfo.length)
		return (flags.width);
	return (floatinfo.length);
}
