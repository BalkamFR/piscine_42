/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:50:12 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/20 10:50:53 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printx(int x)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	if (x >= 1)
	{
		ft_putchar('A');
		x = x - 1;
	}
	while (i != x - 1)
	{
		ft_putchar('B');
		i++;
		temp--;
	}
	if (x >= temp)
		ft_putchar('A');
	ft_putchar('\n');
}

void	printx2(int x)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	if (x >= 1)
	{
		ft_putchar('A');
		x = x - 1;
	}
	while (i != x - 1)
	{
		ft_putchar(' ');
		i++;
	}
	if (x >= temp)
		ft_putchar('A');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	temp;

	temp = y;
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
		return ;
	}
	while (temp != 0)
	{
		if (temp == 1 || temp == y)
			printx(x);
		else
			printx2(x);
		temp--;
	}
}
