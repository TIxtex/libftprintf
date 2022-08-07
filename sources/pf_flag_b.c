#include "ft_printf.h"

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
