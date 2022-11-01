/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:21:39 by uliherre          #+#    #+#             */
/*   Updated: 2022/08/15 11:21:40 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags	fl_hastag(t_flags flags, char **str)
{
	flags.hastag = 1;
	(*str)++;
	return (flags);
}

t_flags	fl_sp(t_flags flags, char **str)
{
	flags.sp = 1;
	(*str)++;
	return (flags);
}

t_flags	fl_plus(t_flags flags, char **str)
{
	flags.plus = 1;
	(*str)++;
	return (flags);
}
