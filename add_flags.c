/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:34:39 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/28 02:29:44 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_flag_zeroe(t_pf *list)
{
	if (list->precision > -1)
	{
		if (ft_printf_strchr("diouxDOUX", list->format) == NULL)
			ft_printf_do_flag_zeroe(list, list->width - list->len);
		return ;
	}
	if (list->format == 'x' || list->format == 'X')
	{
		if (list->diese == 1 && list->width > list->len + 2)
			ft_printf_do_flag_zeroe(list, list->width - (list->len + 2));
		else
			ft_printf_do_flag_zeroe(list, list->width - list->len);
	}
	else if (ft_printf_strchr("Did", list->format)
			&& (list->space == 1 || list->plus == 1)
			&& ft_printf_atoi(list->buff) >= 0)
	{
		if (list->width > list->len + 1)
			ft_printf_do_flag_zeroe(list, list->width - (list->len + 1));
	}
	else if (list->format == 'p' && list->width > list->len + 2)
		ft_printf_do_flag_zeroe(list, list->width - (list->len + 2));
	else
		ft_printf_do_flag_zeroe(list, list->width - list->len);
}

void		ft_printf_flag_space(t_pf *list)
{
	int				i;
	unsigned char	*n_str;

	i = 0;
	if (list->buff[0] != '-')
	{
		n_str = (unsigned char*)malloc(list->len + 2);
		if (ft_printf_atoi(list->buff) > 0)
			n_str[0] = ' ';
		else
		{
			while (list->buff[++i])
				if (list->buff[i] == '-')
					list->buff[i] = '0';
			if (ft_printf_atoi(list->buff) < 0)
				n_str[0] = '-';
			else
				n_str[0] = ' ';
		}
		ft_printf_strcpy(n_str + 1, list->buff);
		n_str[list->len + 1] = '\0';
		free(list->buff);
		list->buff = n_str;
		list->len = ft_printf_strlen(list->buff);
	}
}

void		ft_printf_flag_diese(t_pf *list)
{
	unsigned char	*n_str;

	if ((list->format == 'O' || list->format == 'o') && list->buff[0] != '0')
	{
		n_str = (unsigned char*)malloc(list->len + 2);
		n_str[0] = '0';
		ft_printf_strcpy(n_str + 1, list->buff);
		n_str[list->len + 1] = '\0';
		free(list->buff);
		list->buff = n_str;
		list->len = ft_printf_strlen(n_str);
	}
	else if (((list->format == 'x' || list->format == 'X')
		&& ft_printf_atoi(list->buff) != 0) || list->format == 'p')
	{
		n_str = (unsigned char*)malloc(list->len + 3);
		n_str[0] = '0';
		n_str[1] = 'x';
		ft_printf_strcpy(n_str + 2, list->buff);
		n_str[list->len + 2] = '\0';
		free(list->buff);
		list->buff = n_str;
		list->len = ft_printf_strlen(n_str);
	}
}

void		ft_printf_flag_minus(t_pf *list, unsigned char *n_str)
{
	int		i;

	i = 0;
	n_str = (unsigned char*)malloc(list->width);
	while (i < list->len)
	{
		n_str[i] = list->buff[i];
		i++;
	}
	while (i < list->width)
	{
		n_str[i] = ' ';
		i++;
	}
	n_str[i] = '\0';
	list->len = list->width;
	free(list->buff);
	list->buff = n_str;
}

void		ft_printf_flag_plus(t_pf *list)
{
	int				i;
	unsigned char	*n_str;

	i = 0;
	if (list->buff[0] != '-')
	{
		n_str = (unsigned char*)malloc(list->len + 2);
		if (ft_printf_atoi(list->buff) > 0)
			n_str[0] = '+';
		else
		{
			while (list->buff[++i])
				if (list->buff[i] == '-')
					list->buff[i] = '0';
			if (ft_printf_atoi(list->buff) > 0)
				n_str[0] = '-';
			else
				n_str[0] = '+';
		}
		ft_printf_strcpy(n_str + 1, list->buff);
		n_str[list->len + 1] = '\0';
		free(list->buff);
		list->buff = n_str;
		list->len = ft_printf_strlen(list->buff);
	}
}
