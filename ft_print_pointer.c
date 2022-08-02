/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tixtex <tixtex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:58:47 by tixtex            #+#    #+#             */
/*   Updated: 2020/02/24 18:51:33 by tixtex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_lutoh(unsigned long tohex)
{
	char *str_aux;
	char *str_start;

	str_aux = ft_calloc(13, sizeof(char));
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

void		ft_print_pointer(t_print *print)
{
	t_sstr			*str_aux;
	void			*p;

	str_aux = ft_calloc(1, sizeof(t_sstr));
	p = va_arg(print->ap, void *);
	str_aux->i = (NULL != p) ? ft_lutoh((unsigned long)p) : ft_strdup("0");
	str_aux->len = (0 == *print->flags->point) ? 2 : 2 + ft_strlen(str_aux->i);
	ft_print_sp(print, *print->flags->width, *str_aux);
	write(1, "0x", 2);
	str_aux->len -= 2;
	ft_print_zeros(print, *str_aux);
	str_aux->len += 2;
	write(1, str_aux->i, str_aux->len - 2);
	print->char_print += str_aux->len;
	ft_print_sp(print, *print->flags->neg, *str_aux);
	free(str_aux->i);
	free(str_aux);
}
