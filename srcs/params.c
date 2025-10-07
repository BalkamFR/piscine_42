/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:33:08 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 14:45:48 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*write_params(char *file_name, int params_len)
{
	char	*params;
	int		fdesc;
	int		i;

	i = 0;
	params = malloc(sizeof(char) * params_len);
	fdesc = open(file_name, O_RDONLY);
	while (i < params_len)
		read(fdesc, &params[i++], 1);
	params[i] = '\0';
	close(fdesc);
	return (params);
}

char	*read_params(char *file_name)
{
	char	c;
	int		fdesc;
	int		params_len;

	params_len = 0;
	fdesc = open(file_name, O_RDONLY);
	while (read(fdesc, &c, 1))
	{
		params_len++;
		if (c == '\n' && params_len)
			break ;
	}
	close(fdesc);
	return (write_params(file_name, params_len));
}
