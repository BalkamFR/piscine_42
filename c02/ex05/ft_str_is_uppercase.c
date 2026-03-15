/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:38:07 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 10:27:05 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (str[0] >= 'A' && str[0] <= 'Z')
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
// 	printf("%d\n", ft_str_is_uppercase("stSr"));
// 	printf("%d\n", ft_str_is_uppercase("ST"));
// 	printf("%d\n", ft_str_is_uppercase(""));
// }