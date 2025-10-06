/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:27:40 by equentin          #+#    #+#             */
/*   Updated: 2025/10/06 15:53:37 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	count_all_line(char *file_name)
{
	int		count;
	int		bytes_read;
	int		fdesc;
	int	res;
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
		printf("%s", c);
		res = count_line(c) + res;
	}
	close(fdesc);
	free(c);
	return (res);
}

int	read_file(char *file_name)
{
	int	res;

	res = count_all_line(file_name);

	return(res);
}

int	main(void)
{
	printf("%d", read_file("caca"));
}