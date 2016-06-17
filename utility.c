/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:26:33 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 15:28:28 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned char	*ft_printf_get_null_str(t_pf *list)
{
	unsigned char	*str;

	str = (unsigned char *)ft_printf_strdup((unsigned char*)"(null)");
	if (list->precision < 6 && list->precision != -1)
	{
		str[list->precision] = '\0';
		list->len = list->precision;
	}
	else
		list->len = 6;
	return (str);
}

unsigned char	*ft_printf_strcpy(unsigned char *dst, unsigned char *src)
{
	void	*ptr;

	ptr = dst;
	while (*src)
		*dst++ = *src++;
	*dst++ = *src++;
	dst = ptr;
	return (dst);
}

void			ft_printf_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
		*p++ = 0;
}

char			*ft_printf_strchr(const char *s, int c)
{
	char				*str;
	unsigned char		d;

	str = (char *)s;
	d = c;
	while (*str)
	{
		if (*str == d)
			return (str);
		str++;
	}
	if (*str == d)
		return (str);
	return (NULL);
}

int				ft_printf_strlen(unsigned char *str)
{
	int			len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
