/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:07:08 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/17 16:19:16 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return(i);
}

char *ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i!=ft_strlen(src))
	{
		dest[i] = src[i];
		i++;		
	}
	dest[i] = '\0';
	return(dest);
}

#include<stdio.h>

int	main(void)
{
	char	dest[50]= "";
	char	src[50] = "pacome";
	printf("avant dest : %s, src : %s\n", dest, src);
	ft_strcpy(dest, src);
	printf("avant dest : %s, src : %s", dest, src);

}