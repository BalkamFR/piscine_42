/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:27:40 by equentin          #+#    #+#             */
/*   Updated: 2025/10/06 16:42:52 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_split.h"

int	count_line(char *maps)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (maps[i])
	{
		if (maps[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

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
	return (count);
}

void	fill_map(char *file_name, char **map, int count)
{
	char	*c;
	int		bytes_read;
	int		fdesc;
	int		i;

	i = 0;
	bytes_read = 1;
	
	fdesc = open(file_name, O_RDONLY);
	while (bytes_read != 0)
	{
		map[i] = malloc(sizeof(char) * (count + 1));
		printf("%s\n", map[i]);
		bytes_read = read(fdesc, map[i], count);
		printf("%s", map[i]);
		i++;
	}
	close(fdesc);
}

int	count_all_line(char *file_name, char **map)
{
	int		count;
	int		bytes_read;
	int		fdesc;
	int		res;
	char	*c;

	res = 0;
	bytes_read = 1;
	fdesc = open(file_name, O_RDONLY);
	if (fdesc == -1)
		return (0);
	count = count_line_len(file_name);
	c = malloc(sizeof(char) * count);
	while (bytes_read != 0)
	{
		bytes_read = read(fdesc, c, count);
		res = count_line(c) + res;
	}
	close(fdesc);
	map = malloc(sizeof(char *) * (res + 1));
	fill_map(file_name, map, count);
	map[res] = NULL;
	free(c);
	return (res);
}



char	**read_file(char *file_name)
{
	char	**map;
	int		res;
	int		i;

	i = 0;
	map = 0;
	res = count_all_line(file_name, map);

	// while (map[i] != NULL)
	// {
	// 	printf("%s", map[i]);
	// 	i++;
	// }

	return (map);
}

int	main(void)
{
	read_file("pipi");
	return (0);
}