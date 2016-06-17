/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:16:25 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/28 01:59:59 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_wstr_len(wchar_t *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int		ft_printf_wchar_len(wchar_t c)
{
	int	len;

	len = 0;
	if (c < 0x80)
		return (1);
	len += 2;
	while (c > 0x0000007ff)
	{
		c >>= 6;
		len++;
	}
	return (len);
}

int		ft_printf_wstrstr_len(wchar_t *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_printf_wchar_len(str[i]);
		i++;
	}
	return (len);
}

void	ft_printf_wchar_transform_h(int len, unsigned char **str)
{
	int n;

	n = 0;
	while (n < len)
	{
		**str >>= 1;
		**str |= 0x80;
		n++;
	}
}

void	ft_printf_wchar_transform(wchar_t c, unsigned char *str)
{
	int	len;
	int	n;

	len = ft_printf_wchar_len(c);
	ft_printf_bzero(str, len);
	if (c < 0x80)
	{
		str[0] = c;
		str[1] = '\0';
		return ;
	}
	if (len > 1)
	{
		ft_printf_wchar_transform_h(len, &str);
	}
	n = len;
	while (0 < n)
	{
		n--;
		str[n] |= 0x80 | (c & 0x0000003f);
		c >>= 6;
	}
	str[0] |= c;
	str[len] = '\0';
}
