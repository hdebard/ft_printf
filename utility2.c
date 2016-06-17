/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:28:55 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 15:31:39 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_printf_upper(t_pf *list)
{
	int		i;

	i = 0;
	while (i < list->len)
	{
		if (list->buff[i] >= 97 && list->buff[i] < 123)
			list->buff[i] = list->buff[i] - 32;
		i++;
	}
}

long			ft_printf_atoi(unsigned char *str)
{
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 0;
	while (*str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (int)(*str - '0');
		str++;
	}
	return (sign * nbr);
}

void			ft_printf_check_minus(t_pf *list)
{
	int		i;

	if (ft_printf_strchr("dDi", list->format) != NULL)
	{
		i = 0;
		while (list->buff[i])
		{
			if (list->buff[i] == '-' && i != 0)
			{
				list->buff[i] = '0';
				list->buff[0] = '-';
				break ;
			}
			i++;
		}
	}
}

void			ft_printf_do_flag_zeroe(t_pf *list, int len)
{
	unsigned char	*n_str;
	int				i;
	int				j;

	j = 0;
	n_str = (unsigned char*)malloc(len + list->len);
	i = 0;
	while (i < len)
	{
		n_str[i] = '0';
		i++;
	}
	while (j < list->len)
	{
		n_str[i + j] = list->buff[j];
		j++;
	}
	n_str[i + j] = '\0';
	free(list->buff);
	list->buff = n_str;
	list->len = i + j;
	ft_printf_check_minus(list);
}

unsigned char	*ft_printf_strdup(unsigned char *buff)
{
	unsigned char		*new;
	int					i;

	if ((new = (unsigned char*)malloc(ft_printf_strlen(buff) + 1)) == NULL)
		return (new);
	i = 0;
	while (buff[i])
	{
		new[i] = buff[i];
		i++;
	}
	new[i] = buff[i];
	return (new);
}
