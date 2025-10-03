/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:35:09 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/03 09:45:36 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_valide(char *base)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	if (len_str(base) <= 1)
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

int	convert_value(char find, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == find)
			return (i);
		i++;
	}
	return (0);
}

int	compr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	sign;
	int	len_base;

	i = 0;
	res = 0;
	sign = 1;
	if (base_valide(base) == 0)
		return (0);
	len_base = len_str(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && compr(str[i], base) == 1)
	{
		res = res * len_base + convert_value(str[i], base);
		i++;
	}
	return (res * sign);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	printf("%d", ft_atoi_base(argv[1], argv[2]));
// 	(void)argc;
// 	return (0);
// }