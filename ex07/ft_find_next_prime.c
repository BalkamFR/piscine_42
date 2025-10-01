/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:47:35 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/01 16:48:33 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
		nb++;
	return (nb);
}

#include <stdio.h>

int	main(void)
{
	int	i;
	i = -5;
	while (i < 20)
	{
		printf("nb = %d next prime = %d", i, ft_find_next_prime(i));
		printf("\n-----------------------\n");
		i++;
	}
}