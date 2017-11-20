/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:29:33 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/07/27 16:35:07 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *restrict data, ...)
{
	va_list			var_format;
	va_start(var_format, data);
	unsigned int	len;
	int				width = 0;
	char			*pad = " ";
	size_t			len_2;
	int 			dot;
	int				dot_w = 0;

	dot = 0;
	len = 0;
	len_2 = 0;
	while (data[len] != '\0')
	{
		if (data[len] == '%')
		{
			len++;
			if (data[len] == '\0')
				break;
			while (data[len] == ' ')
				len++;
			if (data[len] == '-')
			{
				pad = "PAD_BACK";
				len++;
			}
			else if (data[len] >= '0' && data[len] <= '9')
				pad = "PAD_FRONT";	
			while (data[len] >= '0' && data[len] <= '9')
			{
				width = (width * 10) + ((int)data[len] - '0');
				len++;
			}
			if (data[len] == '.')
			{
				dot = 1;
				len++;
			}
			while (data[len] >= '0' && data[len] <= '9')
			{
				 dot_w = (dot_w * 10) + ((int)data[len] - '0');
				 len++;
			}//printf("width: %i\n", width);
	
			if (data[len] == 'c')
				len_2 = len_2 + ft_check_chr(data, var_format, len, width, pad);
			if (data[len] == 's')
				len_2 = len_2 + ft_check_s(data, var_format, len, width, pad, dot, dot_w);
			if (data[len] == 'i' || data[len] == 'd')
				len_2 = len_2 + ft_check_i_d(data, var_format, len, width, pad);
			if (data[len] == '%')
				len_2 = ft_check_perc(data, len, width, pad);
			if (data[len] == 'o' || data[len] == 'O')
				len_2 = len_2 + ft_check_o(data, var_format, len, width, pad);
			if (data[len] == 'x' || data[len] == 'X')
				len_2 = len_2 + ft_check_hex(data, var_format, len, width, pad);
			if ((data[len] == 'l' && data[len + 1] == 'x') || (data[len] == 'l' && data[len + 1] == 'X'))
				len_2 = len_2 + ft_check_lon_hex(data, var_format, len, width, pad);
		}
		else
		{
			ft_putchar(data[len]);
			len_2++;
		}
		len++;
	}
	va_end(var_format);
	return (len_2);
}
