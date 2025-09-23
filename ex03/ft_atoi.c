/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:10:31 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/22 14:08:38 by papilaz          ###   ########.fr       */
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
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == ' '))
	{
		if (str[i]=='-')
			sign = sign * -1;
		i++;	
	}
	
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	return (res*sign);
}

int	main(int argc, char **argv)
{
	printf("%d", ft_atoi(argv[1]));
	return(0);
}