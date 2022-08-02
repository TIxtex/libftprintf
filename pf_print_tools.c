#include "ft_printf.h"

int	p_spaces(t_flags flags, int flag, t_ss str)
{
	register int	x;
	char			*aux;

	x = ZERO;
	if (flag > flags.point && flag > (int) str.size)
	{
		if (flags.point > (int) str.size)
		{
			x = flag - flags.point;
			if ('-' == str.str)
				--x;
		}
		else
			x = flag - (int) str.size;
		aux = ft_memset(aux, ' ', x * sizeof(char));
		write(STDOUT_FILENO, aux, x * sizeof(char));
	}
	return (x);
}

int	p_zeros(t_flags flags, t_ss str)
{
	register int	x;
	char			*aux;

	x = ZERO;
	if (flags.point > str.size)
	{
		x = flags.point - str.size;
		aux = ft_memset(aux, '0', x * sizeof(char));
		write(STDOUT_FILENO, aux, x * sizeof(char));
	}
	else if (flags.zero > str.size)
	{
		x = flags.zero - str.size;
		aux = ft_memset(aux, '0', x * sizeof(char));
		write(STDOUT_FILENO, aux, x * sizeof(char));
	}
	return (x);
}

int	p_incrust_zeros(t_flags flags, t_ss str)/* * */
{
	register int	x;
	char			*aux;

	x = ZERO;
	if (flags.point > str.size)
	{
		x = flags.point - str.size;
		if ('-' == str.str)
			--x;
	}
	else if (flags.zero > str.size)
		x = flags.zero - str.size;
	if ('-' == str.str)
	{
		write(STDOUT_FILENO, "-", sizeof(char));
		x++;
	}
	if (ZERO != x - 1)
	{
		aux = ft_memset(aux, '0', (x - 1) * sizeof(char));
		write(STDOUT_FILENO, aux, (x - 1) * sizeof(char));
	}
	return (x);
}
