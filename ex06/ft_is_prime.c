/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:04:38 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/30 09:18:36 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	res;
	int	c;

	c = 1;
	res = 1;
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
// 	printf("%d\n", ft_is_prime(5));
// 	printf("%d\n", ft_is_prime(8));
// 	printf("%d\n", ft_is_prime(11));
// 	printf("%d\n", ft_is_prime(13));
// 	printf("%d\n", ft_is_prime(17));
// 	return (0);
// }