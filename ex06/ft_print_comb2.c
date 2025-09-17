/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:30:33 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/17 16:32:25 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbr2(int nb)
{
	ft_putchar(0 + '0');
	ft_putchar((nb % 10) + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 100)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a <= 9)
				ft_putnbr2(a);
			else
				ft_putnbr(a);
			ft_putchar(' ');
			if (b <= 9)
				ft_putnbr2(b);
			else
				ft_putnbr(b);
			if ((a + b) != 197)
				write(1, " ,", 2);
			b++;
		}
		a++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// 	return (0);
// }