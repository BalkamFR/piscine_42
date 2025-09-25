/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:35:09 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/25 16:50:33 by papilaz          ###   ########.fr       */
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
		return (c - '0');
	return (i);
}

int	int_base(int nb, char *base)
{
	int	len_base;
	int	temp_nb;
	int	i;
	int	res;

	i = 0;
	res = 0;
	temp_nb = 0;
	len_base = len_str(base);
	while (len_base <= nb && nb != 0)
	{
		temp_nb = nb % len_base;
		res = (res * 10);
		res = (char_askii(base[temp_nb]) + res);
		res = (res * 10) + res;
		nb = nb / len_base;
		i++;
	}
	res = (res * 10);
	res = (char_askii(base[temp_nb]) + res);
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;

	return (res);
}

int	main(void)
{
	int	c;

	c = int_base(5, "01");
}
