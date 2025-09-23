/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:35:09 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/23 17:25:35 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	char_askii(char c)
{
	int	i;

	i = c;
	if (c >= '0' && c <= '9')
		return(c - '0');
	return (c);
}

int	int_base(int nb, char *base, char *temp_tab)
{
	int		len_base;
	int		temp_nb;
	int		i;
	char	tab2[] = "";

	i = 0;
	temp_nb = 0;
	len_base = len_str(base);
	while (len_base <= nb && nb != 0)
	{
		temp_nb = nb % len_base;
		temp_tab[i] = base[temp_nb] char_askii();
		nb = nb / len_base;
		i++;
	}
	temp_tab[i] = base[nb];
	temp_tab[i + 1] = '\0';
	temp_nb = 0;
	return (i + 1);
}
int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	neg;

	res = 0;
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (res);
}

int	main(void)
{
	char tab[50] = "";
	int c;

	c = int_base(10, "01", tab);
	printf("%s len : %d\n", tab, c);
	printf("%d", char_askii('a'));

	// printf("\n%d", ft_atoi_base("50", "0123456789"));
}