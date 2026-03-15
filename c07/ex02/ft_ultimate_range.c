/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:41:00 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/09 16:39:10 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	dest = malloc(sizeof(int) * (max - min));
	if (!dest)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
		dest[i++] = min++;
	*range = dest;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int *tab;
	int min;
	int max;
	int len;
	int i;

	min = 0;
	max = 10;

	len = ft_ultimate_range(&tab, min, max);
	i = 0;
	while (i < max - min)
	{
		printf("tab[%d] = %d\n",i ,tab[i]);
		i++;
	}
	printf("len tab : %d\n", len);
	printf("%p", tab);
	free(tab);
	return (0);
}*/