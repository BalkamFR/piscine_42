/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:27:03 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 15:36:33 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/map.h"
#include "../includes/utils.h"
#include "../includes/free.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char		**map;
	int			**square;
	t_params	*params;
	t_coords	coords;

	(void)argc;
	(void)argv;
	map = read_file("test");
	params = malloc(sizeof(t_params));
	write_params(params, map);
	if (is_map_valid(map, params))
	{
		square = malloc(sizeof(int *) * params->size);
		biggest_square_tab(square, params);
		find_square(map, square, params);
		coords = biggest_square(square, params);
		free_all(map, params, square);
	}
	else
		ft_print("map error\n", 2);
	return (0);
}
