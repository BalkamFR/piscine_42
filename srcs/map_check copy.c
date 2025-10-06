/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:27:40 by equentin          #+#    #+#             */
/*   Updated: 2025/10/06 13:28:44 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	read_file(char *file_name)
{
	char	*c;
	char	l;
	int		bytes_read;
	int		file_lenght;
	int		fdesc;
	int		line_lenght;

	while (bytes_read != 0)
	{
		bytes_read = read(fdesc, &l, 1);
		line_lenght++;
		if (l == '\n')
			break ;
	}

	c = malloc(sizeof(char) * line_lenght);
	fdesc = open(file_name, O_RDONLY);
	if (fdesc == -1)
		return (0);
	file_lenght = 0;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fdesc, c, line_lenght);
		file_lenght += bytes_read;
	}
	close(fdesc);
	free(c);
	return (file_lenght);
}