/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:26:23 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/18 21:27:31 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*ft_strlowcase(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	
	// ft_strcpy(str, temp);
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	src[] = "VoTE pour moi STP !!!!!!!!!!!!!!!";

	printf("%s\n", src);
	ft_strlowcase(src);
	printf("%s\n", src);
}