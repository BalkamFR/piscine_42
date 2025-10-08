/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:52:15 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 18:38:21 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/params.h"

void	free_all(char **map, t_params *params, int **square)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	i = 0;
	while (i < params->size)
		free(square[i++]);
	if (square != NULL)
		free(square);
	free(params);
}
