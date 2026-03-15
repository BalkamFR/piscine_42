/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:50:12 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 14:48:18 by thdervau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printx(int x)
{
	int	i;
	int	temp;

	temp = x;
	i = 0;
	if (x >= 1)
	{
		ft_putchar('o');
		x = x - 1;
	}
	while (i < x - 1)
	{
		ft_putchar('-');
		i++;
	}
	if (temp > 1)
		ft_putchar('o');
	ft_putchar('\n');
}

void	printx2(int x)
{
	int	i;
	int	temp;

	temp = x;
	i = 0;
	if (x >= 1)
	{
		ft_putchar('|');
		x = x - 1;
	}
	while (i < x - 1)
	{
		ft_putchar(' ');
		i++;
	}
	if (temp > 1)
		ft_putchar('|');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	temp;

	if (x <= 0 || y <= 0)
		return ;
	temp = y;
	if (x == 1 && y == 1)
	{
		ft_putchar('o');
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
