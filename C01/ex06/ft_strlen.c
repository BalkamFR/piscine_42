/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:09:28 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/17 14:14:11 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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

#include<stdio.h>

int	main(void)
{
	int	a;

	a = ft_strlen("123456789 ");
	printf("%d", a);
}