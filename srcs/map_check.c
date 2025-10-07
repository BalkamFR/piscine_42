/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:27:40 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 17:23:39 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_line_len(char *file_name)
{
	int		count;
	int		bytes_read;
	int		file_lenght;
	int		fdesc;
	char	c[2];

	count = 0;
	file_lenght = 0;
	bytes_read = 1;
	c[1] = 0;
	fdesc = open(file_name, O_RDONLY);
	while (bytes_read != 0)
	{
		bytes_read = read(fdesc, &c[0], 1);
		file_lenght += bytes_read;
		if (c[0] == '\n' && c[1] != 0)
			break ;
		if (c[1] == 1)
			count++;
		if (c[0] == '\n')
			c[1]++;
	}
	close(fdesc);
	return (count + 1);
}

void	fill_map(char *file_name, char **map, int count)
{
	int	bytes_read;
	int	fdesc;
	int	i;

	i = 0;
	bytes_read = 1;
	fdesc = open(file_name, O_RDONLY);
	map[i] = malloc(sizeof(char) * (6)); // TODO: COMPTER VRAIMENT LEN 1ERE LIGNE
	bytes_read = read(fdesc, map[i], 6);
	map[i][5] = '\0';
	i++;
	while (bytes_read != 0)
	{
		map[i] = malloc(sizeof(char) * (count));
		map[i][0] = '\0';
		bytes_read = read(fdesc, map[i], count);
		map[i][count - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fdesc);
}

char	**count_all_line(char *file_name, char **map, int *nb_lines)
{
	int		count;
	int		bytes_read;
	int		fdesc;
	char	*c;

	*nb_lines = 0;
	bytes_read = 1;
	fdesc = open(file_name, O_RDONLY);
	if (fdesc == -1)
		return (0);
	count = count_line_len(file_name);
	c = malloc(sizeof(char) * count);
	while (bytes_read != 0)
	{
		bytes_read = read(fdesc, c, count);
		*nb_lines += 1;
	}
	close(fdesc);
	map = malloc(sizeof(char *) * (*nb_lines + 1));
	fill_map(file_name, map, count);
	map[*nb_lines] = NULL;
	free(c);
	return (map);
}

char	**read_file(char *file_name)
{
	char	**map;
	int		nb_lines;
	int		i;

	i = 0;
	map = 0;
	map = count_all_line(file_name, map, &nb_lines);
	return (map);
}
