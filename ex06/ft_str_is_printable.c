/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:38:54 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 10:25:46 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (str[0] >= 32 && str[0] <= 126)
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
// 	printf("%d\n", ft_str_is_printable(" a"));
// 	printf("%d\n", ft_str_is_printable("ST"));
// 	printf("%d\n", ft_str_is_printable(""));
// }