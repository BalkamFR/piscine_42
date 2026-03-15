/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:35:27 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 10:26:29 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (str[0] >= 'a' && str[0] <= 'z')
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
// 	printf("%d\n", ft_str_is_lowercase("stSr"));
// 	printf("%d\n", ft_str_is_lowercase("st"));
// 	printf("%d\n", ft_str_is_lowercase(""));
// }
