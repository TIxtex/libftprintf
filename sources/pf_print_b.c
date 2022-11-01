/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:21:33 by uliherre          #+#    #+#             */
/*   Updated: 2022/09/12 00:39:52 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utohh(unsigned int tohex)
{
	char	*str_aux;
	char	*str_start;

	str_aux = ft_calloc(9, sizeof(char));
	str_start = str_aux;
	if (tohex == 0)
		*str_aux = '0';
	while (tohex != 0)
	{
		if (tohex % 16 < 10)
			*str_aux = '0' + (tohex % 16);
		else
			*str_aux = 55 + (tohex % 16);
		str_aux++;
		tohex /= 16;
	}
	ft_strrev(str_start);
	return (str_start);
}

char	*ft_lutoh(unsigned long long tohex)
{
	char	*str_aux;
	char	*str_start;

	str_aux = ft_calloc(22, sizeof(char));
	str_start = str_aux;
	if (tohex == 0)
		*str_aux = '0';
	while (tohex != 0)
	{
		if (tohex % 16 < 10)
			*str_aux = '0' + (tohex % 16);
		else
			*str_aux = 87 + (tohex % 16);
		str_aux++;
		tohex /= 16;
	}
	ft_strrev(str_start);
	return (str_start);
}

int	fo_hex(t_flags flags, va_list ap)
{
	register unsigned int	p_n;
	t_ss					sstr;

	p_n = va_arg(ap, unsigned int);
	sstr.str = ft_lutoh(p_n);
	sstr.size = ZERO;
	if ('0' != *sstr.str || ZERO != flags.point)
		sstr.size = ft_strlen(sstr.str);
	if (1 == flags.hastag && p_n)
		p_n = write(STDOUT_FILENO, "0x", 2 * sizeof(char));
	else
		p_n = ZERO;
	p_n += p_spaces(flags, flags.width, sstr);
	p_n += p_zeros_point(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	p_n += p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return ((int) p_n);
}

int	fo_hhex(t_flags flags, va_list ap)
{
	register unsigned int	p_n;
	t_ss					sstr;

	p_n = va_arg(ap, unsigned int);
	sstr.str = ft_utohh(p_n);
	sstr.size = ZERO;
	if ('0' != *sstr.str || ZERO != flags.point)
		sstr.size = ft_strlen(sstr.str);
	if (1 == flags.hastag && p_n)
		p_n = write(STDOUT_FILENO, "0X", 2 * sizeof(char));
	else
		p_n = ZERO;
	p_n += p_spaces(flags, flags.width, sstr);
	p_n += p_zeros_point(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	p_n += p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return ((int) p_n);
}

int	fo_pointer(t_flags flags, va_list ap)
{
	register int			p_n;
	void					*p;
	t_ss					sstr;

	p = va_arg(ap, void *);
	if (NULL == p)
		sstr.str = ft_strdup("0");
	else
		sstr.str = ft_lutoh((unsigned long) p);
	sstr.size = 2;
	if (ZERO != flags.point)
		sstr.size = 2 + ft_strlen(sstr.str);
	p_n = p_spaces(flags, flags.width, sstr);
	p_n += write(STDOUT_FILENO, "0x", 2 * sizeof(char));
	sstr.size -= 2;
	p_n += p_zeros_point(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	sstr.size += 2;
	p_n += p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return (p_n);
}
