/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:58:12 by tixtex            #+#    #+#             */
/*   Updated: 2020/01/28 16:20:26 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(t_print *print)
{
	t_sstr			*str_aux;
	unsigned int	aux_u;

	str_aux = ft_calloc(1, sizeof(t_sstr));
	aux_u = va_arg(print->ap, unsigned int);
	str_aux->i = ft_utoa(aux_u);
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
