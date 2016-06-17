/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:10:38 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 15:14:10 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned char	*ft_printf_char_to_str(char c, t_pf *list)
{
	unsigned char		*str;

	str = (unsigned char*)malloc(2);
	str[0] = (unsigned char)c;
	str[1] = '\0';
	list->len = 1;
	return (str);
}

unsigned char	*ft_printf_str_to_str(char *str, t_pf *list)
{
	unsigned char		*n_str;
	int					len;
	int					i;

	if (str == NULL)
		return (ft_printf_get_null_str(list));
	i = 0;
	len = ft_printf_strlen((unsigned char*)str);
	if (list->precision < len && list->precision != -1)
		n_str = (unsigned char*)malloc(list->precision + 1);
	else
	{
		n_str = (unsigned char*)malloc(len + 1);
		list->precision = len;
	}
	while (i < list->precision && i < len)
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	list->len = i;
	return (n_str);
}

unsigned char	*ft_printf_wchar_to_str(wchar_t c, t_pf *list)
{
	unsigned char	*str;
	int				len;

	len = ft_printf_wchar_len(c);
	str = (unsigned char*)malloc(len + 1);
	ft_printf_wchar_transform(c, str);
	list->len = len;
	return (str);
}

int				ft_printf_wstr_precision(int len, t_pf *list, wchar_t *str)
{
	int			n_len;
	int			tok;

	tok = 0;
	n_len = len;
	if (list->precision < n_len && list->precision != -1)
	{
		n_len = 0;
		if (ft_printf_wchar_len(*str) > 1)
			tok = n_len + 1;
		else
			tok = n_len;
		while (tok < list->precision)
		{
			n_len += ft_printf_wchar_len(*str);
			str++;
			if (ft_printf_wchar_len(*str) > 1)
				tok = n_len + 1;
			else
				tok = n_len;
		}
	}
	return (n_len);
}

unsigned char	*ft_printf_wstr_to_str(wchar_t *str, t_pf *list)
{
	unsigned char	*n_str;
	unsigned char	*temp;
	int				len;
	int				j;
	int				i;

	if (str == NULL)
		return (ft_printf_get_null_str(list));
	i = 0;
	len = ft_printf_wstr_precision(ft_printf_wstrstr_len(str), list, str);
	n_str = (unsigned char*)malloc(len + 1);
	n_str[len] = '\0';
	while (i < len)
	{
		j = -1;
		temp = ft_printf_wchar_to_str(*str, list);
		while (j++ < list->len)
			n_str[i + j] = temp[j];
		i += list->len;
		free(temp);
		str++;
	}
	list->len = len;
	return (n_str);
}
