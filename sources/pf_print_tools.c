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
			if ('-' == *str.str)
				--x;
		}
		else
			x = flag - (int) str.size;
		aux = (char *) malloc(x * sizeof(char));
		if (NULL != aux)
		{
			aux = (char *) ft_memset(aux, ' ', x * sizeof(char));
			write(STDOUT_FILENO, aux, x * sizeof(char));
			free(aux);
		}
	}
	return (x);
}

int	p_zeros(t_flags flags, t_ss str)
{
	register int	x;
	char			*aux;

	x = ZERO;
	if (flags.point > (int) str.size)
	{
		x = flags.point - (int) str.size;
		aux = (char *) malloc(x * sizeof(char));
		if (NULL != aux)
		{
			aux = ft_memset(aux, '0', x * sizeof(char));
			write(STDOUT_FILENO, aux, x * sizeof(char));
			free(aux);
		}
	}
	else if (flags.zero > (int) str.size)
	{
		x = flags.zero - (int) str.size;
		aux = (char *) malloc(x * sizeof(char));
		if (NULL != aux)
		{
			aux = ft_memset(aux, '0', x * sizeof(char));
			write(STDOUT_FILENO, aux, x * sizeof(char));
			free(aux);
		}
	}
	return (x);
}

int	p_incrust_zeros(t_flags flags, t_ss str)/* * */
{
	register int	x;
	register int	p_n;
	char			*aux;

	x = ZERO;
	p_n = ZERO;
	if (flags.point >= (int) str.size)
	{
		x = flags.point - (int) str.size;
		if ('-' == *str.str)
			x++;
	}
	else if (flags.zero > (int) str.size)
		x = flags.zero - (int) str.size;
	if ('-' == *str.str)
	{
		p_n += write(STDOUT_FILENO, "-", sizeof(char));
		str.str += 1;
		str.size -= 1;
	}
	if (0 != x)
	{
		aux = (char *) malloc(x * sizeof(char));
		if (NULL != aux)
		{
			aux = ft_memset(aux, '0', x * sizeof(char));
			p_n += write(STDOUT_FILENO, aux, x * sizeof(char));
			free(aux);
		}
	}
	return (p_n);
}
