/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:09:12 by tixtex            #+#    #+#             */
/*   Updated: 2020/01/28 16:21:49 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_utoh(unsigned int tohex)
{
	char *str_aux;
	char *str_start;

	str_aux = ft_calloc(9, sizeof(char));
	str_start = str_aux;
	if (tohex == 0)
		*str_aux = '0';
	while (tohex != 0)
	{
		*str_aux = (tohex % 16 < 10) ? '0' + (tohex % 16) : 87 + (tohex % 16);
		str_aux++;
		tohex /= 16;
	}
	str_aux = ft_strrev(str_start);
	return (str_aux);
}

static char	*ft_utohh(unsigned int tohex)
{
	char *str_aux;
	char *str_start;

	str_aux = ft_calloc(9, sizeof(char));
	str_start = str_aux;
	if (tohex == 0)
		*str_aux = '0';
	while (tohex != 0)
	{
		*str_aux = (tohex % 16 < 10) ? '0' + (tohex % 16) : 55 + (tohex % 16);
		str_aux++;
		tohex /= 16;
	}
	str_aux = ft_strrev(str_start);
	return (str_aux);
}

void		ft_print_hex(t_print *print)
{
	t_sstr			*str_aux;
	unsigned int	aux_u;

	str_aux = ft_calloc(1, sizeof(t_sstr));
	aux_u = va_arg(print->ap, unsigned int);
	str_aux->i = ('x' == *print->str) ? ft_utoh(aux_u) : ft_utohh(aux_u);
	str_aux->len = ('0' == *str_aux->i && 0 == *print->flags->point)
	? 0 : ft_strlen(str_aux->i);
	ft_print_sp(print, *print->flags->width, *str_aux);
	ft_print_zeros(print, *str_aux);
	write(1, str_aux->i, str_aux->len);
	print->char_print += str_aux->len;
	ft_print_sp(print, *print->flags->neg, *str_aux);
	free(str_aux->i);
	free(str_aux);
}
