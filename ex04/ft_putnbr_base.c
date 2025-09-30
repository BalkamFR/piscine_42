/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:06:04 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/30 17:06:23 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	base_valide(char *base)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (ft_len_base(base) <= 1)
		return (0);
	while (base[i])
	{
		a = i;
		while (base[a])
		{
			if ((base[a] == base[i - 1]) || (base[a] == ' ' || base[a] == '+'
					|| base[a] == '-'))
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int			len_base;
	int			temp_res;
	long int	nb_long;

	nb_long = nb;
	temp_res = 0;
	len_base = ft_len_base(base);
	if (base_valide(base) == 0)
		return ;
	if (nb_long < 0)
	{
		write(1, "-", 1);
		nb_long = nb_long * -1;
	}
	if (nb_long >= len_base)
		ft_putnbr_base((nb_long / len_base), base);
	temp_res = nb_long % len_base;
	write(1, &base[temp_res], 1);
}

// #include<stdlib.h>
// int	main(int argc, char **argv)
// {

// 	ft_putnbr_base(atoi(argv[1]), argv[2]);
// 	write(1, "\n", 1);
// 	(void)argc;
// 	return (0);
// }
