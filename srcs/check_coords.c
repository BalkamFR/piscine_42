/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:33:41 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 15:36:59 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/map.h"
#include <stdlib.h>

int	biggest_square_tab(int **square, t_params *params)
{
	int	x;
	int	y;

	x = 0;
	if (square == NULL)
		return (0);
	while (x < params->size)
	{
		y = 0;
		square[x] = malloc(sizeof(int) * params->size);
		if (square[x] == NULL)
			return (0);
		while (y < params->size)
			square[x][y++] = 0;
		x++;
	}
	return (1);
}

t_coords	biggest_square(int **square, t_params *params)
{
	t_coords	coords;
	int			x;
	int			y;

	coords.x = 0;
	coords.y = 0;
	x = 0;
	while (x < params->size)
	{
		y = 0;
		while (y < params->size)
		{
			if (square[x][y] > square[coords.x][coords.y])
			{
				coords.x = x;
				coords.y = y;
			}
			y++;
		}
		x++;
	}
	return (coords);
}
