/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:35:57 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 20:33:33 by equentin         ###   ########.fr       */
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
			return (0);
		while (j < params->size)
		{
			if (map[i][j] != params->block && map[i][j] != params->empty)
				return (0);
			if (map[i][j] == params->empty)
				findable = 1;
			j++;
		}
		i++;
	}
	if (i - 1 != params->size || findable == 0)
		return (0);
	return (1);
}
