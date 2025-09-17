/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:15:40 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/17 22:57:03 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tab2[size + 15];
	int	i;
	int	temp;

	temp = size;
	i = 0;
	while (i <= temp)
	{
		tab2[i] = tab[size];
		printf("%d\n", tab2[i]);
		size--;
		i++;
	}
	tab2[i + 1] = '\0';
	*tab = *tab2;
}

int	main(void)
{
	int tab[5] = {4, 5, 1};
	int i;
	i = 0;
	while (i != 3)
	{
		printf("%d", tab[i]);
		i++;
	}
	i = 0;
	ft_rev_int_tab(tab, 3);
	printf("\n");
	while (i != 3)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
}