#include "ft_printf.h"

int	fo_percent(t_flags flags, va_list ap)
{
	t_ss			sstr;
	register int	p_n;

	(void) ap;
	sstr.size = 1;
	sstr.str = "%";
	p_n = p_spaces(flags, flags.width, sstr);
	p_n += p_zeros(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sizeof(char));
	p_n += p_spaces(flags, flags.neg, sstr);
	return (p_n);
}

int	fo_int(t_flags flags, va_list ap)
{
	t_ss			sstr;
	register int	p_n;

	p_n = va_arg(ap, int);
	sstr.str = ft_itoa(p_n);
	sstr.size = ZERO;
	if (ZERO != *sstr.str || ZERO != flags.point)
		sstr.size = ft_strlen(sstr.str);
	if (1 == flags.sp && ZERO <= p_n)
		p_n = write(STDOUT_FILENO, " ", 1 * sizeof(char));
	else if (1 == flags.plus && ZERO <= p_n)
		p_n = write(STDOUT_FILENO, "+", 1 * sizeof(char));
	else
		p_n = ZERO;
	p_n += p_spaces(flags, flags.width, sstr);
	p_n += p_incrust_zeros(flags, sstr);
	if ('-' == *sstr.str)
		p_n += write(STDOUT_FILENO, sstr.str + 1, (sstr.size - 1) * sizeof(char));
	else
		p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	p_n += p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return (p_n);
}

int	fo_uint(t_flags flags, va_list ap)
{
	t_ss			sstr;
	register int	p_n;

	sstr.size = va_arg(ap, unsigned int);
	sstr.str = ft_utoa(sstr.size);
	sstr.size = ZERO;
	if (ZERO != *sstr.str || ZERO != flags.point)
		sstr.size = ft_strlen(sstr.str);
	p_n = p_spaces(flags, flags.width, sstr);
	p_n += p_zeros(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	p_n += p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return (p_n);
}

int	fo_char(t_flags flags, va_list ap)
{
	register int	p_n;
	char			aux;
	char			*sp_aux;

	p_n = va_arg(ap, int);
	aux = (char) p_n;
	p_n = ZERO;
	if (flags.width > 1)
	{
		sp_aux = (char *) malloc((flags.width - 1) * sizeof(char));
		sp_aux = (char *) ft_memset((void *) sp_aux, ' ', flags.width - 1);
		p_n += write(STDOUT_FILENO, sp_aux, flags.width - 1);
		free(sp_aux);
	}
	p_n += write(STDOUT_FILENO, &aux, sizeof(char));
	if (flags.neg > 1)
	{
		sp_aux = (char *) malloc((flags.neg - 1) * sizeof(char));
		sp_aux = (char *) ft_memset((void *) sp_aux, ' ', flags.neg - 1);
		p_n += write(STDOUT_FILENO, sp_aux, flags.neg - 1);
		free(sp_aux);
	}
	return (p_n);
}

int	fo_string(t_flags flags, va_list ap)
{
	register int	p_n;
	t_ss			sstr;
	char			*sp_aux;
	char			c;

	sp_aux = &c;
	sstr.str = va_arg(ap, char *);
	if (NULL == sstr.str)
		sstr.str = "(null)";
	sstr.size = ft_strlen(sstr.str);
	if (-1 != flags.point && flags.point < (int) sstr.size)
		sstr.size = (size_t) flags.point;
	p_n = ZERO;
	if (flags.width > (int) sstr.size)
	{
		sp_aux = (char *) malloc((flags.width - sstr.size) * sizeof(char));
		sp_aux = ft_memset((void *) sp_aux, ' ', flags.width - sstr.size);
		p_n += write(STDOUT_FILENO, sp_aux, flags.width - sstr.size);
		free(sp_aux);
	}
	if (flags.zero > (int) sstr.size)
	{
		sp_aux = (char *) malloc((flags.zero - sstr.size) * sizeof(char));
		sp_aux = ft_memset((void *) sp_aux, '0', flags.zero - sstr.size);
		p_n += write(STDOUT_FILENO, sp_aux, flags.zero - sstr.size);
		free(sp_aux);
	}
	p_n +=	write(STDOUT_FILENO, sstr.str, sstr.size);
	if (flags.neg > (int) sstr.size)
	{
		sp_aux = (char *) malloc((flags.neg - sstr.size) * sizeof(char));
		sp_aux = ft_memset((void *) sp_aux, ' ', flags.neg - sstr.size);
		p_n += write(STDOUT_FILENO, sp_aux, flags.neg - sstr.size);
		free(sp_aux);
	}
	return (p_n);
}
