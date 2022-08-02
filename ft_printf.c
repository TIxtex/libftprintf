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

#include "ft_printf.h"

static int	pf_format_handler(va_list ap, char **str)
{
	register char	*door;

	door = ft_strchr(S_FORMAT, **str);
	return(fun_format[door - S_FLAGS](ap, str));
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
	register char	*s;
	int				p_n;

	flags = flags_init();
	s = *str + 1;
	door = ft_strchr(S_FLAGS, (int) *s);
	while (NULL != door)
	{
		str = &s;
		flags = fun_flag[door - S_FLAGS](flags, str);
		door = ft_strchr(S_FLAGS, (int) *s);
	}
	p_n = pf_format_handler(ap, str);
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
			p_n += ft_flag_set_handler(&str);
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
		p_n = ft_core(ap, str);
		va_end(ap);
	}
	return (p_n);
}
