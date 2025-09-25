/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:10:31 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/25 16:40:47 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i]) && ((str[i] <= 32) || (str[i] == ' ' || str[i] == '-'
				|| str[i] == '+')))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("--\n-56d3"));
// 	printf("%d\n", ft_atoi("--n-56d3"));
// 	printf("%d\n", ft_atoi("5656+565656"));
// 	printf("%d\n", ft_atoi("--4544"));
// 	printf("%d\n", ft_atoi("-45645656"));
// 	return (0);
// }