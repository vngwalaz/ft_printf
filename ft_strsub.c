/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 17:19:24 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/06/25 17:19:27 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*my_strsub(char const *s, unsigned int start, size_t len)
{
    char    *res;
    
    res = (char *)malloc(sizeof(char) * (len));
    if (len <= 0)
        return ((char*)s);
    while (*s)
    {
        if ((int)start < (int)len)
        {
            res[start] = s[start];
            start++;
        }
        s++;
    }
    return (res);
}
