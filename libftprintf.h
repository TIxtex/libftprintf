#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_data
{
	vartype		varname;
}				t_data;

/**	libftprintf	**/
int		ft_printf(const char*str, ...);
/**	sources	**/

#endif
