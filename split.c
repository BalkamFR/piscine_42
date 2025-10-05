/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:33:14 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/04 23:42:39 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	ft_lenstr(char *str);


char	**split(char *number_enter)
{
	int		i;
	int		len_str;
	char	**number;

	i = 0;
	len_str = ft_lenstr(number_enter);
	number = malloc((sizeof(char *) * len_str) + 1);
	if (!number)
		return(0) ;
	while (number_enter[i])
	{
		number[i] = malloc(sizeof(char) *  1 + 1);
		number[i][0] = '\0';
		if (!number[i])
			return(0) ;
		number[i][0] = number_enter[i];
		number[i][1] = '\0';
		i++;
	}
	number[i] = NULL;
	return(number);
}
