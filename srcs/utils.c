/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:26:51 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/08 16:00:29 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/utils.h"
#include "../includes/params.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_map_replace(char **maps, int size, t_coords coords, t_params *p)
{
	int	x;
	int	y;
	int	temp_x;
	int	temp_y;

	x = 1;
	while (maps[x])
	{
		if (coords.x + 1 == x)
		{
			temp_x = 0;
			while (temp_x < size)
			{
				y = coords.y;
				temp_y = 0;
				while (temp_y < size)
				{
					maps[x + temp_x][y + temp_y] = p->full;
					temp_y++;
				}
				temp_x++;
			}
		}

		ft_print(maps[x++], 1);
	}
}
