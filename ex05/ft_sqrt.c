/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:49:26 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/30 09:16:05 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	res;
	int	puissance;

	puissance = 1;
	res = 1;
	while (res < nb)
	{
		res = puissance * puissance;
		puissance++;
	}
	if (res == nb)
		return (puissance - 1);
	return (0);
}
// int	main(void)
// {
// 	printf("%d", ft_sqrt(36));
// }