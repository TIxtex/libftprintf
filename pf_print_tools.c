#include "printf.h"

int	p_spaces(t_flags flags, int flag, t_ss str)
{
	register int	x;
	char			*aux;
	char			c;

	aux = &c;
	x = ZERO;
	if (flag > flags.point && flag > (int) str.size)
	{
		if (flags.point > (int) str.size)
		{
			x = flag - flags.point;
			if ('-' == *str.str)
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
	char			c;

	aux = &c;
	x = ZERO;
	if (flags.point > (int) str.size)
	{
		x = flags.point - (int) str.size;
		aux = ft_memset(aux, '0', x * sizeof(char));
		write(STDOUT_FILENO, aux, x * sizeof(char));
	}
	else if (flags.zero > (int) str.size)
	{
		x = flags.zero - (int) str.size;
		aux = ft_memset(aux, '0', x * sizeof(char));
		write(STDOUT_FILENO, aux, x * sizeof(char));
	}
	return (x);
}

int	p_incrust_zeros(t_flags flags, t_ss str)/* * */
{
	register int	x;
	char			*aux;
	char			c;

	aux = &c;
	x = ZERO;
	if (flags.point > (int) str.size)
	{
		x = flags.point - (int) str.size;
		if ('-' == *str.str)
			--x;
	}
	else if (flags.zero > (int) str.size)
		x = flags.zero - (int) str.size;
	if ('-' == *str.str)
		x += write(STDOUT_FILENO, "-", sizeof(char));
	if (ZERO != x - 1)
	{
		aux = ft_memset(aux, '0', (x - 1) * sizeof(char));
		write(STDOUT_FILENO, aux, (x - 1) * sizeof(char));
	}
	return (x);
}
