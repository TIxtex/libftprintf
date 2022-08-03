/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tixtex <tixtex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:54:58 by uherrero          #+#    #+#             */
/*   Updated: 2020/02/24 18:47:36 by tixtex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag_set(t_print *print, int *flag)
{
	*flag = 0;
	if (!ft_isdigit(*print->str) || '0' == *print->str)
		print->str++;
	if (ft_isdigit(*print->str))
	{
		*flag = ft_atoi(print->str);
		while (ft_isdigit(*print->str))
			print->str++;
	}
}

void		ft_flag_set_handler(t_print *print)
{
	ft_set_zero(print->flags);
	while (ft_flag_is_end(*print))
	{
		if (*print->str == '-')
			ft_flag_set(print, print->flags->neg);
		else if (*print->str == '0')
			ft_flag_set(print, print->flags->zero);
		else if (*print->str == '.')
		{
			if (*print->flags->width < *print->flags->zero)
			{
				*print->flags->width = *print->flags->zero;
				*print->flags->zero = -1;
			}
			ft_flag_set(print, print->flags->point);
		}
		else if (ft_isdigit(*print->str))
			ft_flag_set(print, print->flags->width);
		else if (*print->str == '*')
			ft_set_asterisk(print);
	}
	ft_format_select_handler(print);
}
