/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:10:00 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 13:54:15 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	edit_map(int x, int y, char value, char **map);
char	get_coords(int x, int y, char **map);
void	ft_putchar(char c);
void	print_maps(char **maps);
#endif