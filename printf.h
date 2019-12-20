/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 10:50:06 by avan-ber       #+#    #+#                */
/*   Updated: 2019/12/20 15:33:31 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>//

typedef	struct	s_flags
{
	int		dash;
	int		zero;
	int		star;
	int		precision;
	int		prenumber;
	int		width;
	int		plus;
	int		space;
	int		hash;
	int		apostrophe;
	int		length;
}				t_flags;

typedef struct	s_float
{
	long long	nb_before;
	int			nb_before_length;
	long long	nb_after;
	int			nb_after_length;
	int			length;
	int			neg;
	int			power;
	int			nb_zero_sign;
}				t_float;

void		get_format(t_flags *flags, char **str, va_list ap);
int			print_char(t_flags flags, char c);
void		ft_putnbr_hexa_low_fd(unsigned long long nb, int len, int fd);
int			print_hexa_low(t_flags flags, unsigned long long nb);
int			print_hexa_up(t_flags flags, unsigned long long nb);
int			print_int(t_flags flags, long long nb);
int			print_pointer(t_flags flags, void *adress);
int			print_str(t_flags flags, char *str);
int			print_float(t_flags flags, double nb);
int			print_e(t_flags flags, double nb, char cap);
int			print_unsigned_int(t_flags flags, unsigned int nb);
void		ft_putlzero(int len);
void		ft_putlspace(int len);
int			ft_strlen_substr(const char **str, char c);
void		ft_putlstr_fd(char *str, int len, int fd);
size_t		ft_strlen(const char *s);
int			nbr_spacecounter_figure_base(long long nb, int base);
char		*ft_strchr(const char *s, int c);
int			get_print_char_hexa(t_flags flags, int nb, int len);
void		ft_print_sign(t_flags flags, int neg);
int			ft_printf(const char *str, ...);
int			get_print_int(t_flags flags, va_list ap);
int			get_print_unsigned(t_flags flags, va_list ap);
int			get_print_hexa_low(t_flags flags, va_list ap);
int			get_print_hexa_up(t_flags flags, va_list ap);
void		fill_n(t_flags flags, long long int *n);
void		fill_n_int(va_list ap, int count);
void		fill_n_long(va_list ap, int count);
void		fill_n_longlong(va_list ap, int count);
void		fill_n_short(va_list ap, int count);
void		fill_n_shortshort(va_list ap, int count);
int			get_size_n(t_flags flags, va_list ap, int count);
void		setprecisionfloat(t_flags *flags);
void		setfloatinfozero(t_float *floatinfo);
long long	tentothepower(int power);
void		put_float_after(t_flags flags, long long nb);
int			get_figure(long long nb);

#endif