/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tixtex <tixtex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:19:23 by uherrero          #+#    #+#             */
/*   Updated: 2020/02/24 18:51:41 by tixtex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h> /*debug printf*/
# include "libft/libft.h"

# define S_FLAGS "-0.123456789# +"
# define S_FORMAT "idxXcspu%"

typedef struct		s_flags
{
	int				neg;
	int				zero;
	int				point;
	int				width;
	int				hastag;
	int				sp;
	int				plus;
}					t_flags;

typedef struct		s_print
{
	int				char_print;
	const char		*str;
	struct s_flags	*flags;
	va_list			ap;
}					t_print;

int					ft_printf(const char *str, ...);
int					p_spaces(t_flags flags, int flag, t_ss str);
int					p_zeros(t_flags flags, t_ss str);
int					p_incrust_zeros(t_flags flags, t_ss str);/* * */
/**	F_FLAGS	**/
t_flags				fl_neg(t_flags flags, char **str);
t_flags				fl_zero(t_flags flags, char **str);
t_flags				fl_point(t_flags flags, char **str);
t_flags				fl_width(t_flags flags, char **str);
t_flags				fl_asterisk(t_flags flags, char **str);
t_flags				fl_hastag(t_flags flags, char **str);
t_flags				fl_sp(t_flags flags, char **str);
t_flags				fl_plus(t_flags flags, char **str);

/**	F_FORMATS	**/
int					fo_int(t_flags flags, va_list ap);
int					fo_uint(t_flags flags, va_list ap);
int					fo_hex(t_flags flags, va_list ap);
int					fo_hhex(t_flags flags, va_list ap);
int					fo_char(t_flags flags, va_list ap);
int					fo_string(t_flags flags, va_list ap);
int					fo_percent(t_flags flags, va_list ap);
int					fo_pointer(t_flags flags, va_list ap);

#endif
