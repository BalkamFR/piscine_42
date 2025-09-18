/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:01:26 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/18 21:27:12 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
			//str[i] = str[i] - 32;
		i++;
	}
	
	// ft_strcpy(str, temp);
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	src[] = "vote pour moi !!!!!!!!!!!!!!!";

	printf("%s\n", src);
	ft_strupcase(src);
	printf("%s\n", src);
}