/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:42:15 by uliherre          #+#    #+#             */
/*   Updated: 2022/09/12 00:51:21 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_digit_itoa(unsigned int nb, char *str)
{
	if (nb / 10)
		ft_digit_itoa(nb / 10, str + 1);
	*str = '0' + (nb % 10);
}

static size_t	ft_numlen(int num)
{
	register size_t			len;
	register unsigned int	n;

	len = TRUE;
	n = num;
	while (ZERO < n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	register size_t	num_len;
	register char	*str_num;

	str_num = NULL;
	num_len = ft_numlen(n);
	if (ZERO != num_len)
	{
		str_num = (char *) malloc((num_len + 1) * sizeof(char));
		if (NULL == str_num)
			return (NULL);
		str_num[num_len] = '\0';
		ft_digit_itoa(n, str_num);
		ft_strrev(str_num);
	}
	return (str_num);
}
