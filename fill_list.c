/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 14:59:39 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 15:03:49 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_pf					*ft_printf_make_list(void)
{
	t_pf		*list;

	list = (t_pf*)malloc(sizeof(t_pf));
	list->diese = 0;
	list->plus = 0;
	list->space = 0;
	list->minus = 0;
	list->zeroe = 0;
	list->width = 0;
	list->precision = -1;
	list->type = 0;
	list->format = 0;
	list->len = 0;
	list->buff = NULL;
	return (list);
}

int						ft_printf_fill_list(char *str, t_pf *list)
{
	int			ret;

	ret = 0;
	ret += ft_printf_get_flags(str + ret, list);
	ret += ft_printf_get_width_precision(str + ret, list);
	ret += ft_printf_get_type(str + ret, list);
	list->format = str[ret];
	ret++;
	return (ret);
}

int						ft_printf_get_flags(char *str, t_pf *list)
{
	int			ret;

	ret = 0;
	while (ft_printf_strchr("#-0+ ", str[ret]) != NULL)
	{
		if (str[ret] == '0')
			list->zeroe = 1;
		if (str[ret] == '#')
			list->diese = 1;
		if (str[ret] == ' ')
			list->space = 1;
		if (str[ret] == '+')
			list->plus = 1;
		if (str[ret] == '-')
			list->minus = 1;
		ret++;
	}
	if (list->space == 1 && list->plus == 1)
		list->space = 0;
	return (ret);
}

int						ft_printf_get_width_precision(char *str, t_pf *list)
{
	int			ret;

	ret = 0;
	if (ft_printf_strchr("123456789", str[ret]) != NULL)
	{
		list->width = ft_printf_atoi((unsigned char*)str + ret);
		ret += ft_printf_long_len(list->width, 10);
	}
	if (str[ret] == '.')
	{
		ret++;
		if (ft_printf_strchr("0987654321", str[ret]) != NULL)
		{
			list->precision = ft_printf_atoi((unsigned char*)str + ret);
			while (ft_printf_strchr("0123456789", str[ret]) != NULL)
				ret++;
		}
		else
			list->precision = 0;
	}
	return (ret);
}

int						ft_printf_get_type(char *str, t_pf *list)
{
	int			ret;

	ret = 0;
	if (str[ret] == 'h')
	{
		if (str[ret + 1] == 'h')
		{
			list->type = 3;
			ret++;
		}
		else
			list->type = 2;
		ret++;
	}
	else if (str[ret] == 'l' || str[ret] == 'j' || str[ret] == 'z')
	{
		if (str[ret + 1] == 'l' && str[ret] != 'j' && str[ret] != 'z')
			ret++;
		list->type = 1;
		ret++;
	}
	return (ret);
}
