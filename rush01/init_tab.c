/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:52:47 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/28 23:21:56 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	edit_tab(int x, int y, int value, int tab[6][6]);
int		return_tab_x_y(int x, int y, int tab[6][6]);
int		convert_char_int(char c);
void	injection_tab(int tab[6][6]);
void	print_tab_all(int tab[6][6]);
void	print_tab(int tab[6][6]);

int	create_tab_null(int tab[6][6])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= 6)
	{
		while (x < 6)
		{
			tab[x][y] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	init_tab_row(char *tab_char, int tab[6][6])
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (i < 16)
	{
		if (i == 8)
			b = 1;
		if (i < 8)
			edit_tab(b + 1, 0, convert_char_int(tab_char[i]), tab);
		else
			edit_tab(b, 5, convert_char_int(tab_char[i]), tab);
		b++;
		i = i + 2;
	}
}

void	init_tab_col(char *tab_char, int tab[6][6])
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (i < 16)
	{
		if (i == 8)
			b = 1;
		if (i < 8)
			edit_tab(0, b + 1, convert_char_int(tab_char[i + 16]), tab);
		else
			edit_tab(5, b, convert_char_int(tab_char[i + 16]), tab);
		b++;
		i = i + 2;
	}
}

int	init_tab(char *tab_char)
{
	int	tab[6][6];

	create_tab_null(tab);
	init_tab_col(tab_char, tab);
	init_tab_row(tab_char, tab);
	putchar('\n');
	injection_tab(tab);
	putchar('\n');
	print_tab(tab);
	return (0);
}