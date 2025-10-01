/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:49:46 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/01 16:00:13 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (nb);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_recursive_factorial(3));
// 	return (0);
// }