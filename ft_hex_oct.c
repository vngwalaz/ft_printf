/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:02:35 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/06/25 15:47:39 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_o(const char *restrict data, va_list var_format, 
	unsigned int len, int width, char *pad)
{
	int				octal; 
//	unsigned long	o_tel;
	int				count;

	count = 0;
//	o_tel = 0;
	if (data[len] == 'o' || data[len] == 'O')
	{
		octal = va_arg(var_format, int);
		count = ft_convetor_lower(octal, 8, width, pad);
	}
	return (count);
}

int		ft_check_hex(const char *restrict data, va_list var_format, 
	unsigned int len, int width, char *pad)
{
	int hexi;
	unsigned long h_ex;
	int count;

	count = 0;
	h_ex = 1;
	if (data[len] == 'x')
	{
		hexi = h_ex ? va_arg(var_format, long) : va_arg(var_format, int);
		if (hexi == 0)
		{
			ft_putchar('0');
			return (1);
		}
		count = ft_convetor_lower(hexi, 16, width, pad);
	}
	else if (data[len] == 'X')
	{
		hexi = h_ex ? va_arg(var_format, long) : va_arg(var_format, int);
		if (hexi == 0)
		{
			ft_putchar('0');
			return (1);
		}
		count = ft_convetor_upper(hexi, 16, width, pad);
	}
	return (count);
}

int		ft_check_lon_hex(const char *restrict data, va_list var_format, 
	unsigned int len, int width, char *pad)
{
	int hexi;
	unsigned long h_ex;
	int count;

	count = 0;
	h_ex = 1;
	if (data[len] == 'x')
	{
		hexi = h_ex ? va_arg(var_format, long long) : va_arg(var_format, long);
		if (hexi == 0)
		{
			ft_putchar('0');
			return (1);
		}
		count = ft_convetor_long_lower(hexi, 16, width, pad);
	}
	else if (data[len] == 'X')
	{
		hexi = h_ex ? va_arg(var_format, long long) : va_arg(var_format, long);
		if (hexi == 0)
		{
			ft_putchar('0');
			return (1);
		}
		count = ft_convetor_upper(hexi, 16, width, pad);
	}
	return (count);
}

int ft_check_perc(const char *restrict data,unsigned int len, int width, char *pad)
{
	int count;
	int i;

	i = 1;
	count = 0;
	if (data[len] == '%')
	{
		if (ft_strcmp(pad, "PAD_FRONT") == 0)
		{
			while (i < width)
			{
				ft_putchar(' ');
				i++;
			}
		}
		ft_putchar('%');
		count = i;
		if (ft_strcmp(pad, "PAD_BACK") == 0)
		{
			while (i < width)
			{
				ft_putchar(' ');
				--width;
				count++;
			}
		}
	}
	return (count);
}
