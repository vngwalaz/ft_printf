/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 17:18:51 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/06/25 17:18:54 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s)
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
		index++;
	if ((str = (char *)malloc(sizeof(*str) * (index + 1))))
	{
		index = 0;
		while (s[index])
		{
			str[index] = s[index];
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (0);
}
