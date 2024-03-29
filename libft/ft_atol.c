/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:46:57 by uliherre          #+#    #+#             */
/*   Updated: 2022/06/16 20:50:41 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *str)
{
	long			negative;
	unsigned long	value;

	value = ZERO;
	negative = TRUE;
	while (TRUE == ft_isspace(*str))
		str++;
	if ('+' == *str || '-' == *str)
		if ('-' == *(str++))
			negative = -1;
	while (TRUE == ft_isdigit(*str))
		value = value * 10 + *(str++) - '0';
	return ((long) value * negative);
}
