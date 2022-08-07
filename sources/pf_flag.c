#include "ft_printf.h"

t_flags	fl_neg(t_flags flags, char **str)
{
	flags.neg = 0;
	(*str)++;
	if (ft_isdigit(**str))
	{
		flags.neg = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (flags);
}

t_flags	fl_zero(t_flags flags, char **str)
{
	flags.zero = 0;
	(*str)++;
	if (ft_isdigit(**str))
	{
		flags.zero = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (flags);
}

t_flags	fl_point(t_flags flags, char **str)
{
	if (flags.width < flags.zero)
	{
		flags.width = flags.zero;
		flags.zero = -1;
	}
	flags.point = 0;
	(*str)++;
	if (ft_isdigit(**str))
	{
		flags.point = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (flags);
}

t_flags	fl_width(t_flags flags, char **str)
{
	flags.width = ft_atoi(*str);
	while (ft_isdigit(**str))
			(*str)++;
	return (flags);
}
