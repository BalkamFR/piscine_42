/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:30:52 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 10:24:56 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (str[0] >= '0' && str[0] <= '9')
		{
		}
		else
			return (0);
		str++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_str_is_numeric("5d46"));
// 	printf("%d\n", ft_str_is_numeric("45453"));
// 	printf("%d\n", ft_str_is_numeric("4 5453"));
// }