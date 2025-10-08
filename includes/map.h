/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:40:11 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 08:01:22 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../includes/params.h"

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

char		**read_file(char *file_name);
int			is_map_valid(char **map, t_params *params);
int			biggest_square_tab(int **square, t_params *params);
t_coords	biggest_square(int **square, t_params *params);
#endif