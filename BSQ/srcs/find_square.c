/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 08:05:57 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 18:05:46 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/params.h"

int	expand_square(char **map, t_params *params, int x, int y)
{
	int	x_start;
	int	y_start;
	int	size;

	size = 1;
	x_start = x;
	y_start = y;
	while (size <= params->size)
	{
		x = x_start;
		while (x - x_start < size)
		{
			if (x >= params->size)
				return (size - 1);
			y = y_start;
			while (y - y_start < size)
				if (map[x + 1][y++] != params->empty)
					return (size - 1);
			x++;
		}
		size++;
	}
	return (size - 1);
}

void	find_square(char **map, int	**square, t_params *params)
{
	int	x;
	int	y;

	x = 0;
	while (x < params->size)
	{
		y = 0;
		while (y < params->max_line)
		{
			if (map[x + 1][y] == params->empty)
				square[x][y] = expand_square(map, params, x, y);
			y++;
		}
		x++;
	}
}
