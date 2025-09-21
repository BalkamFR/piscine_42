/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:06:51 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 10:24:59 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

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
	return (ft_strlen(i));
}

// #include <stdio.h>
// #include<string.h>

// int	main(void)
// {
// 	char dest[] = "";
// 	char dest2[] = "";
// 	char src[] = "hello";
// 	unsigned int size;

// 	size = 2;

// 	ft_strlcpy(dest, src, size);
// 	printf("ft : %s\n", dest);

// 	strlcpy(dest2, src, size);
// 	printf("ft : %s\n", dest2);
// }