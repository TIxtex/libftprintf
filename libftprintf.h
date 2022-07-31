#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# ifndef FLAGS_M
#  define FLAGS_M "0123456789-*.#+ "
# endif
typedef struct s_flags
{
	int			neg;
	int			zero;
	int			point;
	int			width;
	int			hastag;
	int			space;
	int			plus;
}				t_flags;


typedef struct s_data
{
	int			chars_printed;
	const char	*to_print;
	t_flags		flag;
	va_list		ap;
}				t_data;

/**	libftprintf	**/
int		ft_printf(const char *str, ...);
/**	sources	**/
void	pf_flag_handler(t_data *data);

#endif
