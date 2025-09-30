/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:31:39 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/30 11:41:15 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int *ft_range(int min, int max)
{
	int	*dest;
	int	i;
	
	i = 0;
	dest = malloc(sizeof(int) * (max - min));
	if (!dest)
		return(0);
	min ++;
	while (min < max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	return(dest);	
}

#include<stdio.h>

int	main(void)
{
	int	*res;
	int	i;
	
	res = ft_range(5, 10);
	i = 0;
	while (res[i])
	{
		printf("%d ", res[i]);
		i++;
	}
	free(res);
	return(0);
}