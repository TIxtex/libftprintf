/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:05:38 by uherrero          #+#    #+#             */
/*   Updated: 2020/01/29 16:57:49 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_print *print)
{
	t_ss	*str_aux;

	str_aux = ft_calloc(1, sizeof(t_sstr));
	str_aux->len = va_arg(print->ap, int);
	str_aux->i = ft_itoa(str_aux->len);
	str_aux->len = 
	('0' == *str_aux->i && 0 == *print->flags->point) ? 0 : ft_strlen(str_aux->i);
	ft_print_sp(print, *print->flags->width, *str_aux);
	ft_incrust_zeros(print, str_aux);
	write(1, str_aux->i, str_aux->len);
	print->char_print += str_aux->len;
	ft_print_sp(print, *print->flags->neg, *str_aux);
	free(str_aux->i);
	free(str_aux);
}

