/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:05:33 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/28 01:04:38 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_select_type(t_pf *list, va_list ap)
{
	void	*p;

	if (list->format == 'p')
	{
		p = va_arg(ap, void*);
		if (p == NULL)
			list->buff = long_utoa_base(0, 16);
		else
			list->buff = long_utoa_base((unsigned long)p, 16);
	}
	else if (list->type == 0)
		ft_printf_type_0(list->format, list, ap);
	else if (list->type == 1)
		ft_printf_type_1(list->format, list, ap);
	else if (list->type == 2)
		ft_printf_type_2(list->format, list, ap);
	else if (list->type == 3)
		ft_printf_type_3(list->format, list, ap);
	if (list->len == 0)
		list->len = ft_printf_strlen(list->buff);
	if (ft_printf_strchr("diDuUoOxXp", list->format) != NULL
			&& list->precision > -1)
		ft_printf_add_precision(list);
}

void		ft_printf_type_0(char c, t_pf *list, va_list ap)
{
	if (c == 'd' || c == 'i')
		list->buff = long_itoa_base(va_arg(ap, int), 10);
	else if (c == 'u')
		list->buff = long_utoa_base((unsigned int)va_arg(ap, int), 10);
	else if (c == 'o')
		list->buff = long_utoa_base((unsigned int)va_arg(ap, int), 8);
	else if (c == 'x' || c == 'X')
		list->buff = long_utoa_base((unsigned int)va_arg(ap, int), 16);
	else if (c == 'D')
		list->buff = long_itoa_base((long)va_arg(ap, long), 10);
	else if (c == 'O')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 8);
	else if (c == 'U')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 10);
	else if (c == 'c')
		list->buff = ft_printf_char_to_str(va_arg(ap, int), list);
	else if (c == 's')
		list->buff = ft_printf_str_to_str(va_arg(ap, char*), list);
	else if (c == 'C')
		list->buff = ft_printf_wchar_to_str(va_arg(ap, wchar_t), list);
	else if (c == 'S')
		list->buff = ft_printf_wstr_to_str(va_arg(ap, wchar_t*), list);
}

void		ft_printf_type_1(char c, t_pf *list, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'D')
		list->buff = long_itoa_base((long)va_arg(ap, long), 10);
	else if (c == 'u' || c == 'U')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 10);
	else if (c == 'o' || c == 'O')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 8);
	else if (c == 'x' || c == 'X')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 16);
	else if (c == 'c')
		list->buff = ft_printf_wchar_to_str(va_arg(ap, wchar_t), list);
	else if (c == 's')
		list->buff = ft_printf_wstr_to_str(va_arg(ap, wchar_t*), list);
	else if (c == 'C')
		list->buff = ft_printf_wchar_to_str(va_arg(ap, wchar_t), list);
	else if (c == 'S')
		list->buff = ft_printf_wstr_to_str(va_arg(ap, wchar_t*), list);
}

void		ft_printf_type_2(char c, t_pf *list, va_list ap)
{
	if (c == 'd' || c == 'i')
		list->buff = long_itoa_base((short)va_arg(ap, int), 10);
	else if (c == 'D')
		list->buff = long_utoa_base((long)va_arg(ap, long), 10);
	else if (c == 'u')
		list->buff = long_utoa_base((unsigned short)va_arg(ap, int), 10);
	else if (c == 'U')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 10);
	else if (c == 'o')
		list->buff = long_utoa_base((unsigned short)va_arg(ap, int), 8);
	else if (c == 'O')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, int), 8);
	else if (c == 'x' || c == 'X')
		list->buff = long_utoa_base((unsigned short)va_arg(ap, int), 16);
	else if (c == 'c')
		list->buff = ft_printf_char_to_str(va_arg(ap, int), list);
	else if (c == 's')
		list->buff = ft_printf_str_to_str(va_arg(ap, char*), list);
	else if (c == 'C')
		list->buff = ft_printf_wchar_to_str(va_arg(ap, wchar_t), list);
	else if (c == 'S')
		list->buff = ft_printf_wstr_to_str(va_arg(ap, wchar_t*), list);
}

void		ft_printf_type_3(char c, t_pf *list, va_list ap)
{
	if (c == 'd' || c == 'i')
		list->buff = long_itoa_base((char)va_arg(ap, int), 10);
	else if (c == 'D')
		list->buff = long_utoa_base((long)va_arg(ap, long), 10);
	else if (c == 'u')
		list->buff = long_utoa_base((unsigned char)va_arg(ap, int), 10);
	else if (c == 'U')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 10);
	else if (c == 'O')
		list->buff = long_utoa_base((unsigned long)va_arg(ap, long), 8);
	else if (c == 'o')
		list->buff = long_utoa_base((unsigned char)va_arg(ap, int), 8);
	else if (c == 'x' || c == 'X')
		list->buff = long_utoa_base((unsigned char)va_arg(ap, int), 16);
	else if (c == 'c')
		list->buff = ft_printf_char_to_str(va_arg(ap, int), list);
	else if (c == 's')
		list->buff = ft_printf_str_to_str(va_arg(ap, char*), list);
	else if (c == 'C')
		list->buff = ft_printf_wchar_to_str(va_arg(ap, wchar_t), list);
	else if (c == 'S')
		list->buff = ft_printf_wstr_to_str(va_arg(ap, wchar_t*), list);
}
