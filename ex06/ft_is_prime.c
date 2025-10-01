/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:04:38 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/01 16:45:38 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	res;
	int	c;

	c = 1;
	res = 1;
	if (nb <= 1)
		return (0);
	while (res < nb)
	{
		if (nb % res == 0)
			c++;
		res++;
	}
	if (c > 2)
		return (0);
	return (1);
}

// int	main(void)
// {
// 	int i;
// 	i = -5;
// 	while (i < 20)
// 	{
// 		printf("res = %d nb = %d", ft_is_prime(i), i);
// 		printf("\n----------------\n");
// 		i++;
// 	}
// 	return (0);
// }