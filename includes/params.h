/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:41:44 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 16:14:02 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef struct s_params
{
	int		size;
	int		max_line;
	char	empty;
	char	block;
	char	full;
}	t_params;
void	write_params(t_params *params, char **map);
#endif
