/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:15 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/28 23:24:03 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char str)
{
	write(1, &str, 1);
}

void	swap_tab(char *base_choice, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		base[i] = base_choice[i];
		i++;
	}
	base[i] = '\0';
}

void	swap_base(char *base, int index)
{
	char	*base1;
	char	*base2;
	char	*base3;
	char	*base4;

	base1 = "1234";
	base2 = "2341";
	base3 = "3412";
	base4 = "4123";
	if (index == 1 || index == 6 || index == 11 || index == 16)
		swap_tab(base1, base);
	if (index == 2 || index == 7 || index == 12 || index == 13)
		swap_tab(base2, base);
	if (index == 3 || index == 8 || index == 9 || index == 14)
		swap_tab(base3, base);
	if (index == 4 || index == 5 || index == 10 || index == 15)
		swap_tab(base4, base);
}
void	print_tab_all(int tab[6][6])
{
	int		x;
	int		y;
	char	temp;

	x = 0;
	y = 0;
	while (y < 6)
	{
		while (x < 6)
		{
			temp = (tab[x][y] + '0');
			put_char(temp);
			x++;
		}
		put_char('\n');
		x = 0;
		y++;
	}
}
void	print_tab(int tab[6][6])
{
	int		x;
	int		y;
	char	temp;

	x = 1;
	y = 1;
	while (y < 5)
	{
		while (x < 5)
		{
			temp = (tab[x][y] + '0');
			put_char(temp);
			x++;
		}
		put_char('\n');
		x = 1;
		y++;
	}
}
/*

1 = 5 = 9 = 13
2 = 6 = 10 = 14
3 = 7 = 11 = 15
4 = 8 = 12 = 16

*/

// while	(i < 1024)
// {
// 	while (a <= 4)
// 	{
// 		brut_force_tab(i, base, res);
// 		printf("%s\n", res);
// 		swap_base(base, i);
// 		a++;
// 	}
// 	a = 1;
// 	i++;
// }