/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_itoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:41:15 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 15:56:14 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned char		*long_itoa_base(long nb, int base)
{
	unsigned char		*str;
	int					len;
	int					sign;

	sign = (nb < 0) ? -1 : 1;
	len = ft_printf_long_len(nb, base);
	str = (unsigned char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (nb < 0)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = '0' + nb % base * sign;
		nb /= base;
	}
	return (str);
}

unsigned char		*long_utoa_base(unsigned long nb, int base)
{
	unsigned char		*str;
	int					len;
	int					c;

	len = ft_printf_ulong_len(nb, base);
	str = (unsigned char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		c = '0';
		if (nb % base > 9)
			c += 39;
		str[--len] = c + nb % base;
		nb /= base;
	}
	return (str);
}

int					ft_printf_long_len(long nb, int base)
{
	int			len;

	len = 1;
	if (nb < 0)
		len++;
	while ((nb = nb / base) != 0)
		len++;
	return (len);
}

int					ft_printf_ulong_len(unsigned long nb, int base)
{
	int			len;

	len = 1;
	while ((nb = nb / base) > 0)
		len++;
	return (len);
}
