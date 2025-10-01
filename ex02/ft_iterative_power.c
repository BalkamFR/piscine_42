/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:48:31 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/01 15:55:46 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = n * nb;
		power--;
	}
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_iterative_power(5, 5));
// }