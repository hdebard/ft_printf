/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_and_width.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:39:39 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/28 01:02:24 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_add_precision(t_pf *list)
{
	unsigned char		*n_str;
	int					i;
	int					j;

	j = -1;
	i = 0;
	if (ft_printf_atoi(list->buff) < 0)
		list->precision += 1;
	if (list->precision > list->len)
	{
		n_str = (unsigned char*)malloc(list->precision + 1);
		while (i < list->precision - list->len)
			n_str[i++] = '0';
		while (list->buff[++j])
			n_str[i + j] = list->buff[j];
		n_str[i + j] = '\0';
		free(list->buff);
		list->buff = n_str;
	}
	else if (list->len == 1 && list->buff[0] == '0' && list->precision == 0)
	{
		free(list->buff);
		list->buff = (unsigned char*)ft_printf_char_to_str('\0', list);
	}
	list->len = ft_printf_strlen(list->buff);
}

void		ft_printf_add_width(t_pf *list)
{
	unsigned char	*n_str;
	int				i;

	i = 0;
	n_str = (unsigned char*)malloc(list->width);
	if (list->minus == 1)
		ft_printf_flag_minus(list, n_str);
	else
	{
		while (i < (list->width - list->len))
		{
			n_str[i] = ' ';
			i++;
		}
		while (i < list->width)
		{
			n_str[i] = list->buff[i - (list->width - list->len)];
			i++;
		}
		n_str[i] = '\0';
		list->len = list->width;
		free(list->buff);
		list->buff = n_str;
	}
}
