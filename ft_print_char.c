/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:05:38 by uherrero          #+#    #+#             */
/*   Updated: 2020/01/28 16:20:04 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *print)
{
	int		aux;
	char	*str_aux;

	aux = va_arg(print->ap, int);
	str_aux = ft_strdup((char *)&aux);
	if (*print->flags->width > 1)
		ft_putchar_repeat(print, *print->flags->width - 1, ' ');
	ft_putchar_fd(*str_aux, 1);
	print->char_print += 1;
	if (*print->flags->neg > 1)
		ft_putchar_repeat(print, *print->flags->neg - 1, ' ');
	free(str_aux);
}
