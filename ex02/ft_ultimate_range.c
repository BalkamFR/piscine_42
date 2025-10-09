/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:41:00 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/09 10:03:27 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;
	int	min2;

	i = 0;
	min2 = min;
	dest = malloc(sizeof(int) * (max - min));
	if (!dest)
	{
		*range = NULL;
		return (-1);
	}
	if (!range)
	{
		*range = NULL;
		return (0);
	}
	dest[0] = 0;
	while (min2 < max)
		dest[i++] = min2++;
	*range = dest;
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *tab;
// 	int min;
// 	int max;
// 	int i;

// 	min = 15;
// 	max = 10;
// 	tab = 0;

// 	ft_ultimate_range(&tab, min, max);
// 	i = 0;
// 	while (i < max - min)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }