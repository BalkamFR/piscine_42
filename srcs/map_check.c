/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:35:57 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 10:01:35 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include <stdio.h>

int	is_map_valid(char **map, t_params *params)
{
	int	i;
	int	j;
	int	findable;

	i = 1;
	findable = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][params->size] != '\n')
		{
			printf("Map Validation failed at line = %d, char index = %d : no \\n at end\n", i, params->size);
			return (0);
		}
		while (j < params->size)
		{
			if (map[i][j] != params->block && map[i][j] != params->empty)
			{
				printf("Map Validation failed at line = %d, char index = %d : char not BLOCK or EMPTY\n", i, j);
				return (0);
			}
			if (map[i][j] == params->empty)
				findable = 1;
			j++;
		}
		i++;
	}
	if (i - 1 != params->size || findable == 0)
	{
		printf("Map Validation failed : TOTAL SIZE FOUND %d, FINDABLE %d\n", i - 1, findable);
		return (0);
	}
	return (1);
}
