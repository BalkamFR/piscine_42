/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:33:41 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 08:01:07 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/map.h"
#include <stdlib.h>

int	check_coords_max()
{
	return (0);
}

int	biggest_square_tab(int **square, t_params *params)
{
	int	i;
	int	j;

	i = 0;
	if (square == NULL)
		return (0);
	while (i < params->size)
	{
		j = 0;
		square[i] = malloc(sizeof(int) * params->size);
		if (square[i] == NULL)
			return (0);
		while (j < params->size)
			square[i][j++] = 0;
		i++;
	}
	return (1);
}

t_coords	biggest_square(int **square, t_params *params)
{
	t_coords	coords;
	int	i;
	int	j;

	coords.x = 0;
	coords.y = 0;
	i = 0;
	while (i < params->size)
	{
		j = 0;
		while (j < params->size)
		{
			if (square[i][j] > square[coords.x][coords.y])
			{
				coords.x = i;
				coords.y = j;
			}
			j++;
		}
		i++;
	}
	return (coords);
}
