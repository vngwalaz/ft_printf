/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 10:26:12 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/07/27 16:35:50 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

/*struct mylist {
	const char	*data;
	char		*str;
	char		chr;
	int			len;
	int			number;
	char		perc;
} myList;*/

char	*ft_strdup(const char *s);
char	*ft_itoa(long int nbr);
int		ft_check_perc(const char *restrict data, unsigned int len, int width, char *pad);
int		ft_check_chr(const char *restrict data, va_list var_format, unsigned int len, int width, char *pad);
int		ft_check_s(const char *restrict data, va_list var_format, unsigned int len, int width, char *pad, int dot, int dot_w);
int		ft_check_i_d(const char *restrict data, va_list var_format, unsigned int len, int width, char *pad);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_check_o(const char *restrict data, va_list var_format, unsigned int len, int width, char *pad);
int		ft_check_hex(const char *restrict data, va_list var_format, unsigned int len, int width, char *pad);
int		ft_convetor_lower(unsigned int value, int base, int width, char *pad);
int		ft_convetor_upper(unsigned int value, int base, int width, char *pad);
int		ft_check_lon_hex(const char *restrict data, va_list var_format, unsigned int len, int width, char *pad);
int		ft_convetor_long_lower(unsigned long long value, int base, int width, char *pad);
int		ft_printf(const char *restrict data, ...);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*my_strsub(char const *s, unsigned int start, size_t len);

#endif
