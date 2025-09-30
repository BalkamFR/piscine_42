/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:47:35 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/30 09:14:45 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
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
	{
		while (nb % res == 0)
			res++;
	}
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_find_next_prime(5));
// 	printf("%d\n", ft_find_next_prime(7));
// 	printf("%d\n", ft_find_next_prime(8));
// 	printf("%d ", ft_find_next_prime(12));
// }