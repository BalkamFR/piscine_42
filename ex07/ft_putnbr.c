/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:20:29 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/17 11:32:46 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb<0)
	{
		write(1, "-",1);
		nb = 0 - nb;
	}
	if (nb == 2147483647)
	{
		write(1, "2147483647", 10);
		return;
	}
	if (nb > 10)
	{
		ft_putnbr(nb/10);
	}
	ft_putchar((nb%10) + '0');
}

int	main(void)
{
	ft_putnbr(2147483647);
	return(0);
}