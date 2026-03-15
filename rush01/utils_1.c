/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:25 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/28 23:22:52 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	put_char(char str);

int	convert_char_int(char c)
{
	int	nb;

	nb = c - '0';
	return (nb);
}

void	edit_tab(int x, int y, int value, int tab[6][6])
{
	tab[x][y] = value;
}

int	return_tab_x_y(int x, int y, int tab[6][6])
{
	int	res;

	res = tab[x][y];
	return (res);
}

int	res_ligne(int y, int tab[6][6])
{
	int	res;

	res = 0;
	res = tab[y][1] + tab[y][2] + tab[y][3] + tab[y][4];
	if (res != 10)
		return (0);
	return (1);
}
