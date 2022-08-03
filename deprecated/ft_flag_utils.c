/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uherrero <uherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:53:20 by tixtex            #+#    #+#             */
/*   Updated: 2020/01/29 16:56:13 by uherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_select_handler(t_print *print)
{
	if (*print->str == 'i' || *print->str == 'd')
		ft_print_int(print);
	else if (*print->str == 'x' || *print->str == 'X')
		ft_print_hex(print);
	else if (*print->str == 'c')
		ft_print_char(print);
	else if (*print->str == 's')
		ft_print_string(print);
	else if (*print->str == 'p')
		ft_print_pointer(print);
	else if (*print->str == 'u')
		ft_print_unsigned(print);
	else if (*print->str == '%')
		ft_print_percent(print);
	else
	{
		while ('%' != *print->str)
			print->str--;
	}
	print->str++;
}
