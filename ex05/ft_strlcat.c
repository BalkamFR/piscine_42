/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:34:06 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/25 18:25:29 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	if (size)
	{
		while (dest[i] && i < size)
			i++;
		if (i >= size)
			return (size + src_len);
		while (src[j] && (i + j) < (size - 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (i + src_len);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	dest[50] = "dsd";
	char	src[50] = "123456";
	unsigned int	size = 4;

	printf("%d \n", ft_strlcat(dest, src, size));
	return (0);
}*/
