/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:33:08 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 18:57:33 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_param_ok(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[i] == str[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	write_params(t_params *params, char **map)
{
	int		params_len;
	char	jsp[4];

	params_len = ft_strlen(map[0]);
	jsp[0] = map[0][params_len - 1];
	jsp[1] = map[0][params_len - 2];
	jsp[2] = map[0][params_len - 3];
	jsp[3] = '\0';
	if (is_param_ok(jsp) == 0)
		return (0);
	params->max_line = ft_strlen(map[1]);
	params->full = map[0][params_len - 1];
	params->block = map[0][params_len - 2];
	params->empty = map[0][params_len - 3];
	map[0][params_len - 3] = '\0';
	params->size = ft_atoi(map[0]);
	return (1);
}
