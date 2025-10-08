/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:33:08 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 16:14:38 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/params.h"
#include "../includes/utils.h"

void	write_params(t_params *params, char **map)
{
	int	params_len;

	params_len = ft_strlen(map[0]);
	params->max_line = ft_strlen(map[1]);
	params->full = map[0][params_len - 1];
	params->block = map[0][params_len - 2];
	params->empty = map[0][params_len - 3];
	map[0][params_len - 3] = '\0';
	params->size = ft_atoi(map[0]);
}
