/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:27:03 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 20:30:40 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/free.h"
#include "../includes/map.h"
#include "../includes/params.h"
#include "../includes/utils.h"
#include <stdlib.h>

void	read_all_map(char *name_map)
{
	char		**map;
	int			**square;
	t_params	*params;
	t_coords	coords;

	map = read_file(name_map);
	if (map[0] == 0)
	{
		ft_print("map error\n", 2);
		return ;
	}
	params = malloc(sizeof(t_params));
	square = NULL;
	if (write_params(params, map) && is_map_valid(map, params))
	{
		square = malloc(sizeof(int *) * params->size);
		biggest_square_tab(square, params);
		find_square(map, square, params);
		coords = biggest_square(square, params);
		print_map_replace(map, square[coords.x][coords.y], coords, params);
	}
	else
		ft_print("map error\n", 2);
	free_all(map, params, square);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			read_all_map(argv[i]);
			i++;
		}
	}
	return (0);
}
