/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:26:51 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/07 17:47:29 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	edit_map(int x, int y, char value, char **map)
{
	map[x + 1][y] = value;
}

char	get_coords(int x, int y, char **map)
{
	return (map[x + 1][y]);
}

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

void	print_maps(char **maps)
{
	int	i;
	int	a;

	a = 0;
	i = 1;
	while (maps[i])
	{
		a = 0;
		while (maps[i][a] && maps[i])
		{
			ft_putchar(maps[i][a]);
			a++;
		}
		i++;
	}
}
