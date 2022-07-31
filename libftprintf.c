#include "./libftprintf.h"

static void	pf_char_handler(t_data *d)
{
	register size_t	size;
	register char	*start;

	size = ZERO;
	start = d->to_print;
	while ('%' != *d->to_print && '\0' != *d->to_print)
	{
		size++;
		d->chars_printed++;
		d->to_print++;
	}
	if (ZERO != size)
		write(STDOUT_FILENO, start, size * sizeof(const char));
	if ('%' == *d->to_print)
	{
		d->to_print++;
		pf_flag_handler(d);
	}
}

static void	pf_init(t_data *data)
{
	data->chars_printed = ZERO;
	data->flag.neg = -1;
	data->flag.zero = -1;
	data->flag.point = -1;
	data->flag.width = -1;
	data->flag.hastag = -1;
	data->flag.space = -1;
	data->flag.plus = -1;
}

int	ft_printf(const char *str, ...)
{
	t_data	d;

	if (NULL == str)
		return (ZERO);
	pf_init(&d);
	d.to_print = str;
	va_start(d.ap, str);
	while ('\0' != *d.to_print) 
		pf_char_handler(&d);
	va_end(d.ap);
	return (d.chars_printed);
}
