/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:56:58 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/27 17:13:17 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	convert_char_int(char c)
{
	int	nb;

	nb = c - '0';
	return (nb);
}

void	print_tab(int tab[6][6][6])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 6)
	{
		while (x < 6)
		{
			printf("%d ", tab[5][x][y]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void	edit_tab(int x, int y, int value, int tab[6][6][6])
{
	tab[5][x][y] = value;
}

int	return_tab_x_y(int x, int y, int tab[6][6][6])
{
	int	res;

	res = tab[5][x][y];
	return (res);
}

int	create_tab_null(int tab[6][6][6])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= 6)
	{
		while (x < 6)
		{
			tab[5][x][y] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
void	init_tab_row(char *tab_char, int tab[6][6][6])
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

void	init_tab_col(char *tab_char, int tab[6][6][6])
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

void	edit(int find, int value, int tab[6][6][6])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 6)
	{
		if (x == 6)
		{
			y = y + 1;
			x = 0;
		}
		if (return_tab_x_y(x, y, tab) == find)
		{
			if (x == 0)
				edit_tab(x + 1, y, value, tab);
			if (y == 0)
				edit_tab(x, y + 1, value, tab);
			if (x == 5)
				edit_tab(x - 1, y, value, tab);
			if (y == 5)
				edit_tab(x, y - 1, value, tab);
		}
		x++;
	}
}

void	edit_ed(int tab[6][6][6])
{
	
	
}



int	init_tab(char *tab_char)
{
	int	tab[6][6][6];

	create_tab_null(tab);
	init_tab_col(tab_char, tab);
	init_tab_row(tab_char, tab);
	printf("%d\n", return_tab_x_y(0, 4, tab));
	print_tab(tab);
	// edit(4, 1, tab);
	edit_ed(tab);
	printf("\n\n");
	print_tab(tab);
	return (0);
}

/*
col1top col2top col3top col4top x
col1bottom col2bottom col3bottom col4bottom  x

row1left row2left row3left row4left y
row1right row2right row3right row4right y
*/

int	main(int argc, char **argv)
{
	init_tab("0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0");
	// init_tab("4 3 2 1 1 2 2 2 0 3 2 1 1 2 2 2");
	
	(void)argc;
	(void)argv;
	return (0);
}