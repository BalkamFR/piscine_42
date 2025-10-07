/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:41:44 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 14:38:05 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef struct s_params
{
	int		size;
	char	empty;
	char	block;
	char	full;
}	t_params;
char	*read_params(char *file_name);
#endif
