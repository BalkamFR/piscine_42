/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:49:26 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/01 16:07:29 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;
	int	puissance;

	puissance = 0;
	res = 1;
	while (nb > 0)
	{
		nb = nb - res;
		res = res + 2;
		puissance++;
	}
	if (nb != 0)
		return (0);
	return (puissance);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_sqrt(25));
// }