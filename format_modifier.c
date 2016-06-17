/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 14:58:09 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/28 01:07:54 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_format_modifier(char *str, va_list ap, int *ret)
{
	t_pf		*list;
	int			i;

	if (str[1] == '\0')
		return (1);
	list = ft_printf_make_list();
	i = 1;
	i += ft_printf_fill_list(str + i, list);
	ft_printf_get_format(list, ap);
	if (list->format != 0)
		ft_printf_check_flags(list);
	ft_printf_write(list->buff, list->len);
	*ret += list->len;
	free(list->buff);
	free(list);
	return (i);
}

void		ft_printf_get_format(t_pf *list, va_list ap)
{
	if (ft_printf_strchr("scdiouDOUxXpCS", list->format) != NULL)
		ft_printf_select_type(list, ap);
	else
	{
		list->buff = ft_printf_char_to_str(list->format, list);
		list->len = 1;
	}
}

void		ft_printf_check_flags(t_pf *list)
{
	ft_printf_check_minus(list);
	if (list->zeroe == 1 && list->width > list->len && list->minus == 0)
		ft_printf_flag_zeroe(list);
	ft_printf_check_minus(list);
	if (list->space == 1 && ft_printf_strchr("dDi", list->format) != NULL)
		ft_printf_flag_space(list);
	else if (list->plus == 1 && ft_printf_strchr("dDi", list->format) != NULL)
		ft_printf_flag_plus(list);
	else if ((list->diese == 1 && ft_printf_strchr("xXoO", list->format)
				!= NULL) || list->format == 'p')
		ft_printf_flag_diese(list);
	if (list->format == 'X')
		ft_printf_upper(list);
	if (list->width > list->len)
		ft_printf_add_width(list);
}
