/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:41:00 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/08 15:45:37 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	dest = malloc(sizeof(int) * (max - min));
	if (!dest)
		return (-1);
	if (!range)
		return (0);
	dest[0] = 0;
	while (min < max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	*range = dest;
	return (min - max);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *tab;
// 	int min;
// 	int max;
// 	int i;

// 	min = 1;
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