/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:27:03 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 17:30:07 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/map_check.h"
#include "../includes/utils.h"
#include "../includes/free.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char		**map;
	t_params	*params;

	(void)argc;
	(void)argv;
	map = read_file("pipi");
	print_maps(map);
	params = malloc(sizeof(t_params));
	write_params(params, map);
	printf("EMPTY : %c\n", params->empty);
	printf("BLOCK : %c\n", params->block);
	printf("FULL : %c\n", params->full);
	printf("SIZE OF MAP : %d\n", params->size);
	free_all(map, params);
	return (0);
}
