#include "printf.h"

int	fo_hex(t_flags flags, char **str, va_list ap)
{
	register unsigned int	p_n;
	t_ss					sstr;

	(void)str;
	p_n = va_arg(ap, unsigned int);
	if ('x' == **str)
		sstr.str = ft_utoh(p_n);
	else
		sstr.str = ft_utohh(p_n);
	sstr.size = ZERO;
	if ('0' != *sstr.str || ZERO != flags.point)
		sstr.size = ft_strlen(sstr.str);
	p_n = p_spaces(flags, flags.width, sstr);
	p_n += p_zeros(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	p_n = p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return ((int) p_n);
}

int	fo_pointer(t_flags flags, char **str, va_list ap)
{
	register int			p_n;
	void 					*p;
	t_ss					sstr;

	(void)str;
	p = va_arg(ap, void *);
	if (NULL == p)
		sstr.str = ft_strdup("0");
	else
		sstr.str = ft_lutohh((unsigned long) p);
	sstr.size = 2;
	if (ZERO != flags.point)
		sstr.size = 2 + ft_strlen(sstr.str);
	p_n = p_spaces(flags, flags.width, sstr);
	p_n += write(STDOUT_FILENO, "0x", 2 * sizeof(char));
	sstr.size -= 2;
	p_n += p_zeros(flags, sstr);
	p_n += write(STDOUT_FILENO, sstr.str, sstr.size * sizeof(char));
	sstr.size += 2;
	p_n += p_spaces(flags, flags.neg, sstr);
	free(sstr.str);
	return (p_n);
}