/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conveter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:57:07 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/11/20 08:44:45 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_convetor_lower(unsigned int value, int base, int width, char *pad)
{
	char	*p, buff[(sizeof(long) * 50 / 3) + 1];
	int		i;
	int 	count;

	i = 0;
	p = buff;
	count = 0;
	while (value > 0)
	{
		*p++ = "0123456789abcdef"[value % base];
		value /= base;
		i++;
	}
	if (ft_strcmp(pad, "PAD_FRONT") == 0)
	{
		while ((width - i) > 0)
		{
			ft_putchar(' ');
			width--;
			count++;
		}
		
	}
	while (p > buff)
		ft_putchar(*--p);
	if (ft_strcmp(pad, "PAD_BACK") == 0)
	{
		 while ((width - i) > 0)
		 {
			 ft_putchar(' ');
			 width--;
			 count++;
		 }
	}
	return(count + i);
}

int		ft_convetor_upper(unsigned int value, int base, int width, char *pad)
{
	char	*p, buff[(sizeof(long) * 43 / 3) + 1];
	int		i;
	int		count;

	count = 0;
	i = 0;
	p = buff;
	while (value > 0)
	{
		*p++ = "0123456789ABCDEF"[value % base];
		value /= base;
		i++;
	}
	if (ft_strcmp(pad, "PAD_FRONT") == 0)
	{
		while ((width - i) > 0)
		{
			ft_putchar(' ');
			width--;
		}
	}
	while (p > buff || count++ <= 8)
		ft_putchar(*--p);
	if (ft_strcmp(pad, "PAD_BACK") == 0)
	{
		while ((width - i) > 0)
		{
			ft_putchar(' ');
			width--;
		}
	}
	return (i);
}

int		ft_convetor_long_lower(unsigned long long value, int base, int width, char *pad)
{
	char	*p, buff[(sizeof(long) * 50 / 3) + 1];
	int		i;
	int 	count;

	i = 0;
	p = buff;
	count = 0;
	while (value > 0)
	{
		*p++ = "0123456789abcdef"[value % base];
		value /= base;
		i++;
	}
	if (ft_strcmp(pad, "PAD_FRONT") == 0)
	{
		while ((width - i) > 0)
		{
			ft_putchar(' ');
			width--;
			count++;
		}
		
	}
	while (p > buff)
		ft_putchar(*--p);
	if (ft_strcmp(pad, "PAD_BACK") == 0)
	{
		 while ((width - i) > 0)
		 {
			 ft_putchar(' ');
			 width--;
			 count++;
		 }
	}
	return(count + i);
}
