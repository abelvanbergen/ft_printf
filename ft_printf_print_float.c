/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_float.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:29:55 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/23 15:51:08 by avan-ber      ########   odam.nl         */
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
	floatinfo->neg = 0;
	if (nb < 0 || *(unsigned long long *)&nb == 0x8000000000000000)
		floatinfo->neg = 1;
	floatinfo->nb_before_length =
				nbr_spacecounter_figure_base(floatinfo->nb_before, 10);
	nb -= floatinfo->nb_before;
	if (floatinfo->neg == 1)
		nb *= -1;
	res = tentothepower(flags.prenumber);
	floatinfo->nb_after = nb * res;
	if (nb == 0.5 && flags.prenumber == 0)
		floatinfo->nb_before += floatinfo->nb_before % 2;
	else
	{
		if (floatinfo->nb_after % 10 >= 5)
			floatinfo->nb_after += 10 - (floatinfo->nb_after % 10);
	}
	floatinfo->nb_after /= 10;
	if (nbr_spacecounter_figure_base(floatinfo->nb_after, 10) >
				flags.prenumber && floatinfo->nb_after != 0)
	{
		floatinfo->nb_after = 0;
		if (floatinfo->neg == 1)
		{
			floatinfo->nb_before--;
			if ((nbr_spacecounter_figure_base(floatinfo->nb_before, 10) >
						floatinfo->nb_before_length))
				floatinfo->nb_before_length++;
		}
		else
		{
			floatinfo->nb_before++;
			if ((nbr_spacecounter_figure_base(floatinfo->nb_before, 10) >
						floatinfo->nb_before_length))
				floatinfo->nb_before_length++;
		}
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

int	print_float_edge(char *str, int len, t_flags flags, int neg)
{
	if (flags.plus == 1 || flags.space == 1 || neg == 1)
		flags.width--;
	if (flags.width > len && flags.dash == 0)
		ft_putlspace(flags.width - len);
	ft_print_sign(flags, neg);
	ft_putlstr_fd(str, len, 1);
	if (flags.width > len && flags.dash == 1)
		ft_putlspace(flags.width - len);
	if (flags.width > len)
		return (flags.width);
	return (len);
}

int	float_check_edge(double nb, int cap, t_flags flags)
{
	if (nb > __DBL_MAX__)
	{
		if (cap == 1)
			return (print_float_edge("INF", 3, flags, 0));
		else
			return (print_float_edge("inf", 3, flags, 0));
	}
	if (nb < __DBL_MAX__ * -1)
	{
		if (cap == 1)
			return (print_float_edge("INF", 3, flags, 1));
		else
			return (print_float_edge("inf", 3, flags, 1));
	}
	if (nb != nb)
	{
		flags.plus = 0;
		flags.space = 0;
		if (cap == 1)
			return (print_float_edge("NAN", 3, flags, 0));
		else
			return (print_float_edge("nan", 3, flags, 0));
	}
	return (0);
}

int	print_float(t_flags flags, double nb, int cap)
{
	int		check;
	t_float floatinfo;

	if (flags.prenumber > 30)
		return (-1);
	check = float_check_edge(nb, cap, flags);
	if (check > 0)
		return (check);
	setprecisionfloat(&flags);
	setfloatinfozero(&floatinfo);
	get_floatinfo(flags, &floatinfo, nb);
	if (flags.width > floatinfo.length && flags.dash == 0)
		print_float_width_front(flags, floatinfo);
	if (flags.zero == 0 || flags.width <= floatinfo.length)
		ft_print_sign(flags, floatinfo.neg);
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
