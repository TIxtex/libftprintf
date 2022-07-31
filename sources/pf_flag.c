#include "libftprintf.h"

void	pf_flag_point (t_data *data);
{
			if (*print->flags->width < *print->flags->zero)
			{
				*print->flags->width = *print->flags->zero;
				*print->flags->zero = -1;
			}
			ft_flag_set(print, print->flags->point);
}

static void	ft_flag_set(t_print *print, int *flag)
{
	int		num;

	*flag = 0;
	if (!ft_isdigit(*print->str) || '0' == *print->str)
		print->str++;
	if (ft_isdigit(*print->str))
	{
		*flag = ft_atoi(print->str);
		while (ft_isdigit(*print->str))
			print->str++;
	}
	else if ('*' == *print->str)
	{
		num = va_arg(print->ap, int);
		if (flag == print->flags->point && num < 0)
			*print->flags->point = -1;
		if (num > 0)
			*flag = num;
		else if (flag != print->flags->point)
		{
			*print->flags->point = -1;
			*print->flags->neg = -1 * num;
		}
		print->str++;
	}
}

void	pf_flag_handler (t_data *data)
{
	while (NULL != ft_strchr(FLAGS_M, (int) d->to_print) && '\0'== *d->to_print)
	{
		if (*print->str == '-')
			ft_flag_set(print, print->flags->neg);
		else if (*print->str == '0')
			ft_flag_set(print, print->flags->zero);
		else if (*print->str == '.')
			pf_flag_point(data);
		else if (ft_isdigit(*print->str))
			ft_flag_set(print, print->flags->width);
		else if (*print->str == '*')
			ft_set_asterisk(print);
		else if ()
			pf_flag_set(*print->str == ' ');
		else if ()
			pf_flag_set(*print->str == '#');
		else if ()
			pf_flag_set(*print->str == '+');
	}
	pf_format_handler(d);
}
