#include "ft_printf.h"

void	ft_print_sp(t_print *print, int flag, t_sstr str)
{
	int		num;

	num = 0;
	if (flag > *print->flags->point && flag > str.len)
	{
		if (*print->flags->point > str.len)
		{
			num = flag - *print->flags->point;
			if ('-' == *str.i)
				num--;
		}
		else
			num = flag - str.len;
		ft_putchar_repeat(print, num, ' ');
	}
}

int	ft_print_zeros(t_print *print, t_ss str)
{
	if (*print->flags->point > str.len)
	{
		write();
		ft_putchar_repeat(print, *print->flags->point - str.len, '0');
		return ();
	}
	if (*print->flags->zero > str.len)
	{
		write();
		ft_putchar_repeat(print, *print->flags->zero - str.len, '0');
		return ();
	}
	return (ZERO);
}

void	ft_incrust_zeros(t_print *print, t_sstr *str)
{
	int		num;
	char	*str_aux;

	num = 0;
	if (*print->flags->point > str->len)
	{
		num = *print->flags->point - str->len;
		if ('-' == *str->i)
			num++;
	}
	else if (*print->flags->zero > str->len)
		num = *print->flags->zero - str->len;
	if ('-' == *str->i)
	{
		ft_putchar_repeat(print, 1, '-');
		str_aux = ft_substr(str->i, 1, str->len - 1);
		free(str->i);
		str->len--;
		str->i = str_aux;
		if (*print->flags->neg > 0)
			(*print->flags->neg)--;
	}
	if (num)
		ft_putchar_repeat(print, num, '0');
}
