/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:45:53 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/07 11:26:12 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	edit_map(int x, char **maps, char find, int value[])
{
	int	i;
	int	a;

	// printf("%d : %d \nx = %d \n", value[0], value[1], x);
	a = 0;
	i = 0;
	while (maps[i])
	{
		a = 0;
		while (maps[i][a] && maps[i])
		{
			if (x == a && value[0] == i)
				maps[i][a] = '0';
			a++;
		}
		i++;
	}
}

void	find_line(char **maps, int x, char find)
{
	int	y;
	int	a;
	int	count;
	int	value[30];

	count = 0;
	a = 0;
	y = x;
	while (x <= 30)
	{
		if (find == maps[x][0])
		{
			value[count] = x;
			count++;
		}
		x++;
	}
	value[count] = 0;
	printf("%d", value[0]);
	edit_map(y, maps, find, value);
}
