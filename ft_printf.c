/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 14:56:10 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 14:57:07 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printf(char *str, ...)
{
	int		ret;
	int		i;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += ft_printf_format_modifier(str + i, ap, &ret);
		else
		{
			ft_printf_write((unsigned char*)str + i, 1);
			i++;
			ret++;
		}
	}
	return (ret);
}

void			ft_printf_write(unsigned char *str, size_t len)
{
	write(1, str, len);
}
