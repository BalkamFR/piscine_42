/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:52:36 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/25 19:49:32 by papilaz          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	a;

	i = ft_strlen(dest);
	a = 0;
	while (src[a])
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest[50] = "vote pour moi ";
	char dest2[50] = "vote pour moi ";
	char src[50] = "dqw";
	char src2[50] = "dqw";
	ft_strcat(dest, src);
	strcat(dest2, src2);

	printf("faux dest : %s\n", dest);
	printf("vrais dest : %s", dest2);
}*/