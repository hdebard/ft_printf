/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 14:37:33 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/27 15:24:11 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_pf
{
	int				diese;
	int				plus;
	int				space;
	int				minus;
	int				zeroe;
	int				width;
	int				precision;
	int				type;
	int				format;
	int				len;
	unsigned char	*buff;
}					t_pf;

int					ft_printf(char *str, ...);
void				ft_printf_write(unsigned char *str, size_t len);
int					ft_printf_format_modifier(char *str, va_list ap, int *ret);
t_pf				*ft_printf_make_list(void);
void				ft_printf_get_format(t_pf *list, va_list ap);
void				ft_printf_check_flags(t_pf *list);
int					ft_printf_fill_list(char *str, t_pf *list);
int					ft_printf_get_flags(char *str, t_pf *list);
int					ft_printf_get_width_precision(char *str, t_pf *list);
int					ft_printf_get_type(char *str, t_pf *list);
void				ft_printf_select_type(t_pf *list, va_list ap);
void				ft_printf_type_0(char c, t_pf *list, va_list ap);
void				ft_printf_type_1(char c, t_pf *list, va_list ap);
void				ft_printf_type_2(char c, t_pf *list, va_list ap);
void				ft_printf_type_3(char c, t_pf *list, va_list ap);
unsigned char		*ft_printf_char_to_str(char c, t_pf *list);
unsigned char		*ft_printf_str_to_str(char *str, t_pf *list);
unsigned char		*ft_printf_wchar_to_str(wchar_t c, t_pf *list);
unsigned char		*ft_printf_wstr_to_str(wchar_t *str, t_pf *list);
int					ft_printf_wstr_precision(int len, t_pf *list, wchar_t *str);
int					ft_printf_wstr_len(wchar_t *str);
int					ft_printf_wchar_len(wchar_t c);
int					ft_printf_wstrstr_len(wchar_t *str);
void				ft_printf_wchar_transform(wchar_t c, unsigned char *str);
void				ft_printf_wchar_transform_h(int len, unsigned char **str);
unsigned char		*long_utoa_base(unsigned long nbr, int base);
int					ft_printf_ulong_len(unsigned long nbr, int base);
unsigned char		*long_itoa_base(long nbr, int base);
int					ft_printf_long_len(long nbr, int base);
void				ft_printf_add_precision(t_pf *list);
void				ft_printf_add_width(t_pf *list);
void				ft_printf_flag_space(t_pf *list);
void				ft_printf_flag_diese(t_pf *list);
void				ft_printf_flag_minus(t_pf *list, unsigned char *n_str);
void				ft_printf_flag_zeroe(t_pf *list);
void				ft_printf_flag_plus(t_pf *list);
unsigned char		*ft_printf_strcpy(unsigned char *dst, unsigned char *src);
int					ft_printf_strlen(unsigned char *str);
char				*ft_printf_strchr(const char *s, int c);
void				ft_printf_bzero(void *s, size_t n);
unsigned char		*ft_printf_get_null_str(t_pf *list);
void				ft_printf_upper(t_pf *list);
long				ft_printf_atoi(unsigned char *str);
void				ft_printf_check_minus(t_pf *list);
void				ft_printf_do_flag_zeroe(t_pf *list, int len);
unsigned char		*ft_printf_strdup(unsigned char *buff);

#endif
