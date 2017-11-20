/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:14:56 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/07/27 16:35:29 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_chr(const char *restrict data, va_list var_format,
     unsigned int len, int width, char *pad)
{
    char	chr;
    int		i;

    i = 1;

    if (data[len] == 'c')
    {
        chr = (char)va_arg(var_format, int);
        if (ft_strcmp(pad, "PAD_FRONT") == 0)
        {
            while (i < width)
            {
                ft_putchar(' ');
                i++;
            }
            ft_putchar(chr);
        }
        else if (ft_strcmp(pad, "PAD_BACK") == 0)
        {
            ft_putchar(chr);
            while (i < width)
            {
                ft_putchar(' ');
                i++;
            }
        }
    }
    return (i + 1);
}

int		ft_check_s(const char *restrict data, va_list var_format, 
    unsigned int len, int width, char *pad, int dot, int dot_w)
{
    char	*str;
    int		i;
    int		count;

    i = 0;
    count = 0; 
    str = va_arg(var_format, char*);
    width = width - ft_strlen(str);
    if (data[len] == 's')
    {
        if (ft_strcmp(pad, "PAD_FRONT") == 0)
        {
            while (i < width)
            {
                ft_putchar(' ');
                i++;
            }
            count = i;
        }
        if (dot == 1)
            ft_putstr(my_strsub(str, 0, (size_t)dot_w));
        else
            ft_putstr(str);
        if (ft_strcmp(pad, "PAD_BACK") == 0)
        {
            while (i < width)
            {
                ft_putchar(' ');
                i++;
                count++;
            }
        }
    }
    return (ft_strlen(str) + count);
}

int		ft_check_i_d(const char *restrict data, va_list var_format, 
    unsigned int len, int width, char *pad)
{
    int		number;
    int		count;

    count = 0;
    number = va_arg(var_format, int);
    width = width - ft_strlen(ft_itoa(number));
    if (data[len] == 'i' || data[len] == 'd')
    {
        if (ft_strcmp(pad, "PAD_FRONT") == 0)
        {
            while (width > 0)
            {
                ft_putchar(' ');
                --width;
                count++;
            }
        }
        ft_putnbr(number);
        if (ft_strcmp(pad, "PAD_BACK") == 0)
        {
            while (width > 0)
            {
                ft_putchar(' ');
                --width;
                count++;
            }
        }
    }
    return (ft_strlen(ft_itoa(number)) + count);
}
