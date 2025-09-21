/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:06:51 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 10:24:53 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i != ft_strlen(src))
	{
		if (i < n)
			dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
	}
	return (dest);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char	dest[50]= "";
// 	char	src[50] = "pacome pilaz";
// 	printf("avant src : %s\n", dest);
// 	ft_strncpy(dest, src, 7);
// 	printf("src : %s", dest);

// }