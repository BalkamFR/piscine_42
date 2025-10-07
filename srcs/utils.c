/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:26:51 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/07 11:33:23 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_maps(char **maps)
{
	int i;
	int a;

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