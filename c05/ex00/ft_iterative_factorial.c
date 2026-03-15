/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:14:29 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/01 15:47:25 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

// #include<stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_iterative_factorial(0));
// 	return(0);
// }