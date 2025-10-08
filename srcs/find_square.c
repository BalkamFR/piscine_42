/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:05:57 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 12:14:39 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/params.h"
#include <stdio.h>

int	expand_square_y(char **map, t_params *params, int x, int y)
{
	int	x_start;
	int	y_start;
	int	size;

	size = 0;
	x_start = x;
	y_start = y;
	while (y < params->size && map[x][y + 1] == params->empty)
		y++;
	size = 1 + y - y_start;
	if (size == 1)
		return (1);
	while (x < params->size && x + 1 < size
		&& map[x + 1][y_start] == params->empty)
	{
		y = y_start;
		while (y < params->size && map[x][y + 1] == params->empty)
			y++;
		if (1 + y - y_start != size)
			break ;
		x++;
	}
	size = 1 + x - x_start;
	return (size);
}

int	expand_square_x(char **map, t_params *params, int x, int y)
{
	int	x_start;
	int	y_start;
	int	size;

	size = 0;
	x_start = x;
	y_start = y;
	while (x < params->size && map[x + 1][y] == params->empty)
		x++;
	size = 1 + x - x_start;
	if (size == 1)
		return (1);
	while (y < params->size && y + 1 < size
		&& map[x_start][y + 1] == params->empty)
	{
		x = x_start;
		while (x < params->size && map[x + 1][y] == params->empty)
			x++;
		if (1 + x - x_start != size)
			break ;
		y++;
	}
	size = 1 + y - y_start;
	return (size);
}

int	expand_square(char **map, t_params *params, int x, int y)
{
	//int	size_x;
	int	size_y;

	//size_x = expand_square_x(map, params, x, y);
	size_y = expand_square_y(map, params, x, y);
	//printf("\n####\nMAX SIZE FOR (%d,%d) FROM X : %d\n", x, y, size_x);
	printf("MAX SIZE FOR (%d,%d) FROM Y : %d\n", x, y, size_y);
	//if (size_x > size_y)
	//	return (size_x);
	return (size_y);
}

void	find_square(char **map, int	**square, t_params *params)
{
	int	x;
	int	y;

	x = 1;
	while (x < params->size)
	{
		y = 0;
		while (y < params->size)
		{
			if (map[x][y] == params->empty)
				square[x][y] = expand_square(map, params, x, y);
			y++;
		}
		x++;
	}
}

