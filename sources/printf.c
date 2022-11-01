/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:14:26 by uherrero          #+#    #+#             */
/*   Updated: 2022/08/15 12:05:46 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		(*g_f_fo[10])(t_flags, va_list) = {
	&fo_int, &fo_int,
	&fo_hex, &fo_hhex,
	&fo_char,
	&fo_string,
	&fo_pointer,
	&fo_uint,
	&fo_percent,
	NULL
};

static t_flags	(*g_f_fl[16])(t_flags, char **) = {
	&fl_neg,
	&fl_zero,
	&fl_point,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_hastag,
	&fl_sp,
	&fl_plus,
	NULL
};

static int	pf_format_handler(t_flags flags, char **str, va_list ap)
{
	int			x;
	char		*door;
	const char	*format;

	format = S_FORMAT;
	door = ft_strchr(format, **str);
	x = door - format;
	return (g_f_fo[x](flags, ap));
}

static t_flags	flags_init(void)
{
	t_flags	flags;

	flags.neg = -1;
	flags.zero = -1;
	flags.point = -1;
	flags.width = -1;
	flags.hastag = -1;
	flags.sp = -1;
	flags.plus = -1;
	return (flags);
}

static int	pf_flag_set_handler(va_list ap, char **str)
{
	t_flags			flags;
	register char	*door;
	int				p_n;

	flags = flags_init();
	(*str)++;
	door = ft_strchr(S_FLAGS, (int) **str);
	while (NULL != door)
	{
		flags = g_f_fl[door - S_FLAGS](flags, str);
		door = ft_strchr(S_FLAGS, (int) **str);
	}
	p_n = pf_format_handler(flags, str, ap);
	(*str)++;
	return (p_n);
}

static int	ft_core(va_list ap, char *str)
{
	int		p_n;
	size_t	size;

	p_n = ZERO;
	while (ZERO != *str)
	{
		size = ZERO;
		while ('%' != str[size] && ZERO != str[size])
			size++;
		if (ZERO != size)
		{
			p_n += write(STDOUT_FILENO, str, size);
			str += size;
		}
		while ('%' == *str)
		{
			p_n += pf_flag_set_handler(ap, &str);
		}
	}
	return (p_n);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		p_n;

	p_n = 0;
	if (NULL != str)
	{
		va_start(ap, str);
		p_n = ft_core(ap, (char *)str);
		va_end(ap);
	}
	return (p_n);
}
