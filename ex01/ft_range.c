/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:31:39 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/08 21:17:52 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	dest = malloc(sizeof(int) * (max - min));
	if (!dest)
		return (0);
	while (i < max - min)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}

// #include<stdio.h>

// int	main(void)
// {
// 	int	*res;
// 	int	i;
// 	int	min;
// 	int	max;

// 	min = 5;
// 	max = 10;

// 	res = ft_range(min, max);
// 	i = 0;
// 	while (i < max - min)
// 	{
// 		printf("%d ", res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return(0);
// }