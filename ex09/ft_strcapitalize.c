/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:28:34 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/18 22:01:53 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




char	*ft_strcapitalize(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')||(str[i] >= 'a' && str[i] <= 'z'))
			str[i] += 32;
		i++;
	}
	
	// ft_strcpy(str, temp);
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	src[] = "Hi, How Are You? 42words Forty-Two; Fifty+And+One";

	printf("%s\n", src);
	ft_strcapitalize(src);
	printf("%s\n", src);
}