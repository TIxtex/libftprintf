/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:21:31 by uliherre          #+#    #+#             */
/*   Updated: 2022/09/12 02:38:11 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	p_aux(char print, int size)
{
	char	*aux;

	if (ZERO != size)
	{
		aux = (char *) ft_memset((char *) malloc(size), print, size);
		if (NULL != aux)
		{
			write(STDOUT_FILENO, aux, size * sizeof(char));
			free(aux);
		}
	}
	return (size);
}

int	p_spaces(t_flags flags, int flag, t_ss str)
{
	register int	x;

	x = ZERO;
	if (flag > flags.point && flag > (int) str.size)
	{
		if (flags.point > (int) str.size)
		{
			x = flag - flags.point;
			if ('-' == *str.str)
				--x;
		}
		else
			x = flag - (int) str.size;
		p_aux(' ', x);
	}
	return (x);
}

static int	p_zeros_zero(t_flags flags, t_ss str)
{
	register int	x;

	x = ZERO;
	if (flags.zero > (int) str.size)
	{
		x = flags.zero - (int) str.size;
		p_aux('0', x);
	}
	return (x);
}

int	p_zeros_point(t_flags flags, t_ss str)
{
	register int	x;

	x = ZERO;
	if (flags.point > (int) str.size)
	{
		x = flags.point - (int) str.size;
		p_aux('0', x);
	}
	else
		x = p_zeros_zero(flags, str);
	return (x);
}

int	p_incrust_zeros(t_flags flags, t_ss str)
{
	register int	x;
	register int	p_n;

	x = ZERO;
	p_n = ZERO;
	if (flags.point >= (int) str.size)
	{
		x = flags.point - (int) str.size;
		if ('-' == *str.str)
			x++;
	}
	else if (flags.zero > (int) str.size)
		x = flags.zero - (int) str.size;
	if ('-' == *str.str)
	{
		p_n += write(STDOUT_FILENO, "-", sizeof(char));
		str.str += 1;
		str.size -= 1;
	}
	p_n += p_aux('0', x);
	return (p_n);
}
