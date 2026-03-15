/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:15:40 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/19 11:20:08 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tab2[2000000];
	int	i;
	int	temp;

	temp = size;
	i = 0;
	while (i <= temp)
	{
		tab2[i] = tab[size];
		size--;
		i++;
	}
	i = 0;
	while (i != temp + 1)
	{
		tab[i] = tab2[i];
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int tab[4] = {4, 3, 2, 1};
// 	int i;
// 	i = 0;
// 	while (i != 4)
// 	{
// 		printf("%d", tab[i]);
// 		i++;
// 	}
// 	i = 0;
// 	ft_rev_int_tab(tab, 3);
// 	printf("\n");
// 	while (i != 4)
// 	{
// 		printf("%d", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// }