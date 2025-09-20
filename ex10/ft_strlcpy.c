/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:06:51 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/20 11:45:21 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && size > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(i);
}

#include <stdio.h>

int	main(void)
{
	char dest[] = "";
	char src[] = "hello";
	unsigned int size;

	size = 2;

	ft_strlcpy(dest, src, size);
	printf("%s", dest);
}