/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:07:34 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/09 17:14:23 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	size_all_tab(char **strs, char *sep, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (strs[i])
	{
		if (size - 1 >= i)
			res = res + len_str(strs[i]) + len_str(sep);
		i++;
	}
	return (res);
}

void	cat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = len_str(dest);
	while (src[i])
	{
		dest[i + size] = src[i];
		i++;
	}
	dest[i + size] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (size_all_tab(strs, sep, size) + 1));
	if (!dest)
		return (0);
	dest[0] = '\0';
	while (size > i && strs[i])
	{
		cat(dest, strs[i]);
		if (size - 1 > i)
			cat(dest, sep);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char *src;
	src = ft_strjoin(argc - 1, argv + 1, "hello");
	free(src);
	(void)argv;
	(void)argc;
	return (0);
}*/