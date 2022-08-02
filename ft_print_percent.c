/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:05:38 by uherrero          #+#    #+#             */
/*   Updated: 2020/01/14 14:13:35 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_print *print)
{
	t_sstr	str_aux;

	str_aux.size = 1;
	str_aux.str = NULL;
	ft_print_sp(print, *print->flags->width, str_aux);
	ft_print_zeros(print, str_aux);
	write(STDOUT_FILENO, "%%", sizeof(char));
	print->char_print += 1;
	ft_print_sp(print, *print->flags->neg, str_aux);
}
