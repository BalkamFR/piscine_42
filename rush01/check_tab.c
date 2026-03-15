/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:47:40 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/28 23:35:08 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	return_tab_x_y(int x, int y, int tab[6][6]);

int	tab_check_left(int tab[6][6], int line)
{
	int	i;
	int	compt;
	int	max;

	i = 1;
	compt = 0;
	max = 0;
	while (i <= 4)
	{
		if (max < return_tab_x_y(0, line, tab))
		{
			max = return_tab_x_y(i, line, tab);
			compt++;
		}
		i++;
	}
	if (compt == tab[0][line])
		return (0);
	return (1);
}

int	tab_check_right(int tab[6][6], int line)
{
	int	i;
	int	compt;
	int	max;

	i = 4;
	compt = 0;
	max = 0;
	while (i >= 1)
	{
		if (max < return_tab_x_y(5, line, tab))
		{
			max = return_tab_x_y(i, line, tab);
			compt++;
		}
		i--;
	}
	if (compt == tab[0][line])
		return (0);
	return (1);
}
