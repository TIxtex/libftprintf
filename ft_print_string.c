/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:05:38 by uherrero          #+#    #+#             */
/*   Updated: 2020/01/27 19:01:47 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_zeros_s(t_print *print, t_sstr str)
{
	if (*print->flags->zero > str.len)
		ft_putchar_repeat(print, *print->flags->zero - str.len, '0');
}

void		ft_print_string(t_print *print)
{
	t_sstr	*str_aux;

	str_aux = ft_calloc(1, sizeof(t_sstr));
	if (NULL == (str_aux->i = va_arg(print->ap, char *)))
		str_aux->i = ft_strdup("(null)");
	else
		str_aux->i = ft_strdup(str_aux->i);
	str_aux->len = ft_strlen(str_aux->i);
	if (*print->flags->point < str_aux->len && *print->flags->point != -1)
		str_aux->len = *print->flags->point;
	if (*print->flags->width > str_aux->len)
		ft_putchar_repeat(print, *print->flags->width - str_aux->len, ' ');
	ft_print_zeros_s(print, *str_aux);
	write(1, str_aux->i, str_aux->len);
	free(str_aux->i);
	print->char_print += str_aux->len;
	if (*print->flags->neg > str_aux->len)
		ft_putchar_repeat(print, *print->flags->neg - str_aux->len, ' ');
	free(str_aux);
}
