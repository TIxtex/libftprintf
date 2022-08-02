#include "ft_printf.h"

t_flags	fl_hastag(t_flags flags, char **str)
{
	flags.hastag = 1;
	(*str)++;
	if (ft_isdigit(**str))
	{
		flags.hastag = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (flags);
}

t_flags	fl_sp(t_flags flags, char **str)
{
	flags.sp = 1;
	(*str)++;
	if (ft_isdigit(**str))
	{
		flags.sp = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (flags);
}

t_flags	fl_plus(t_flags flags, char **str)
{
	flags.plus = 1;
	(*str)++;
	if (ft_isdigit(**str))
	{
		flags.plus = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (flags);
}
