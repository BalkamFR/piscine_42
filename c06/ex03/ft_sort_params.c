/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:09:30 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/25 21:33:05 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	askii_tab(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res + str[i];
		i++;
	}
	return (res);
}

void	sort_tab(int *str)
{
	int	i;
	int	temp;

	i = 1;
	temp = 0;
	while (str[i])
	{
		while (str[i - 1] > str[i])
		{
			temp = str[i];
			str[i] = str[i - 1];
			str[i - 1] = temp;
			i--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	a;
	int	i;
	int	tab[5000];

	i = 0;
	while (i + 1 < argc)
	{
		tab[i] = askii_tab(argv[i + 1]);
		i++;
	}
	sort_tab(tab);
	i = 1;
	a = 0;
	while (a < argc - 1)
	{
		if (tab[a] == askii_tab(argv[i]))
		{
			ft_putstr(argv[i]);
			ft_putstr("\n");
			a++;
			i = 0;
		}
		i++;
	}
	return (0);
}
