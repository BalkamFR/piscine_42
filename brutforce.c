/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:05:31 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/28 23:32:31 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap_base(char *base, int index);
// void	swap_base_1(char *base, int index);
// void	swap_base_2(char *base, int index);
// void	swap_base_3(char *base, int index);

int		tab_check_left(int tab[6][6], int line);
int		tab_check_right(int tab[6][6], int line);
int		tab_col_right(int tab[6][6], int line);
int		tab_col_left(int tab[6][6], int line);

int	verif_tab(char *str)
{
	int	i;
	int	a;
	int	len;

	a = 0;
	len = 0;
	i = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		a = i + 1;
		while (a <= len)
		{
			if (str[a] == str[i])
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

char	*brut_force_tab(int nb, char *base, char *res)
{
	int	len_base;
	int	temp_nb;
	int	i;

	i = 0;
	temp_nb = 0;
	len_base = 4;
	while (len_base <= nb && nb != 0)
	{
		temp_nb = nb % len_base;
		res[i] = base[temp_nb];
		nb = nb / len_base;
		i++;
	}
	res[i] = '\0';
	if (verif_tab(res) == 1)
		return (res);
	return (0);
}

void	insert_value_tab(int tab[6][6], int line, char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		tab[i + 1][line] = (value[i] - '0');
		i++;
	}
}

void	injection_tab(int tab[6][6])
{
	int		i;
	char	res[5];
	int		a;
	char	base[5] = "1234";

	i = 256;
	a = 1;
	while (i < 1024)
	{
		if (brut_force_tab(i, base, res) != 0)
		{
			while (a <= 4)
			{
				if (tab_check_left(tab, a) == 1 && tab_check_right(tab, a) == 1)
					insert_value_tab(tab, a, base);
				swap_base(base, a);
				a++;
			}
			a = 1;
		}
		i++;
	}
}
