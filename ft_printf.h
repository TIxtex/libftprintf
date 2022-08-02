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
# include <stdio.h>//debug printf
# include "libft/libft.h"

# define S_FLAGS "-0.123456789# +"
#define S_FORMAT "idxXcspu\%"

typedef t_flags (*f_fl)(t_flags, char **);
typedef int (*f_fo)(t_flags, char **);

const static f_fl fun_flag[16] = {
	&fl_neg,
	&fl_zero,
	&fl_point,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_width,
	&fl_hastag,
	&fl_sp,
	&fl_plus,
	NULL
};

const static f_fo fun_format[10] = {
	&fo_int, &fo_int,
	&fo_hex, &fo_hex,
	&fo_char,
	&fo_string,
	&fo_pointer,
	&fo_uint,
	&fo_percent,
	NULL
};

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
void				pf_flag_set_handler(va_list ap, char **str);
void				ft_format_select_handler(t_print *print);
void				ft_print_int(t_print *print);
void				ft_putchar_repeat(t_print *print, int num, char c);
void				ft_print_char(t_print *print);
void				ft_print_string(t_print *print);
void				ft_print_unsigned(t_print *print);
void				ft_print_hex(t_print *print);
void				ft_print_pointer(t_print *print);
void				ft_print_percent(t_print *print);
void				ft_print_sp(t_print *print, int flag, t_ss str);
void				ft_print_zeros(t_print *print, t_ss str);
void				ft_incrust_zeros(t_print *print, t_ss *str);
void				ft_incrust_zeros_neg(t_ss *str, char *zs_aux,
					char *str_aux);

int	p_spaces(t_flags flags, int flag, t_ss str)
int	p_zeros(t_flags flags, t_ss str)
int	p_incrust_zeros(t_flags flags, t_ss str)/* * */
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

#endif
