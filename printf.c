/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tixtex <tixtex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:14:26 by uherrero          #+#    #+#             */
/*   Updated: 2020/02/24 18:45:30 by tixtex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int (*f_fo[10])(t_flags, char **, va_list) = {
	&fo_int, &fo_int,
	&fo_hex, &fo_hex,
	&fo_char,
	&fo_string,
	&fo_pointer,
	&fo_uint,
	&fo_percent,
	NULL
};

static t_flags (*f_fl[16])(t_flags, char **) = {
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
	register char	*door;

	door = ft_strchr(S_FORMAT, **str);
	return(f_fo[door - S_FLAGS](flags, str, ap));
}

static t_flags flags_init(void
)
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
	char	*s;

	flags = flags_init();
	s = *str + 1;
	door = ft_strchr(S_FLAGS, (int) *s);
	while (NULL != door)
	{
		str = &s;
		flags = f_fl[door - S_FLAGS](flags, str);
		door = ft_strchr(S_FLAGS, (int) *s);
	}
	return (pf_format_handler(flags, str, ap));
}

static int	ft_core(va_list ap, char *str)
{
	int		p_n;
	size_t	size;

	p_n = ZERO;
	while (ZERO != *str)
	{
		size = ZERO;
		while ('%' != *str && ZERO != *str)
			size++;
		if (ZERO != size)
		{
			write(STDOUT_FILENO, str, size);
			str += size;
			p_n += size;
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
