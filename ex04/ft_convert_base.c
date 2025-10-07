/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:14:49 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/07 21:39:12 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int	check_nbr(char *nbr, char c)
{
	long int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

long int	check_number_valide(char *nbr, char *base)
{
	long int	len;
	long int	i;
	long int	a;

	a = 0;
	len = 0;
	i = 0;
	while ((nbr[a] >= 9 && nbr[a] <= 13) || (nbr[a] == 32 || nbr[a] == '-'
			|| nbr[a] == '+'))
		a++;
	while (nbr[a])
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == nbr[a])
				len++;
			i++;
		}
		a++;
	}
	if (len == len_str(nbr + a))
		return (1);
	return (0);
}

long int	convert_value(char find, char *base)
{
	long int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == find)
			return (i);
		i++;
	}
	return (0);
}
long int	base_valide(char *base)
{
	long int	i;
	long int	a;

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

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	i;
	int	len_base;
	int	sign;

	i = 0;
	sign = 1;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	len_base = len_str(base);
	while (check_nbr(base, str[i]) == 1)
	{
		res = res * len_base + convert_value(str[i], base);
		i++;
	}
	return (res * sign);
}

int	invert_tab(char *str)
{
	int		i;
	int		len;
	char	*res;

	len = len_str(str);
	res = malloc((sizeof(char) * len) + 1);
	if (!res)
		return (0);
	i = 0;
	res[i] = '\0';
	while (len > 0)
	{
		res[i] = str[len - 1];
		len--;
		i++;
	}
	i = 0;
	while (str[i])
	{
		str[i] = res[i];
		i++;
	}
	free(res);
	return (0);
}

char	*ft_putnbr_base(long int nb, char *base, char *res)
{
	long int	sign;
	long int	temp_nb;
	long int	i;

	i = 0;
	temp_nb = 0;
	sign = 0;
	if (nb < 0)
		sign = 1;
	if (nb < 0)
		nb = nb * -1;
	while (len_str(base) <= nb)
	{
		temp_nb = nb % len_str(base);
		res[i] = base[temp_nb];
		nb = nb / len_str(base);
		i++;
	}
	temp_nb = nb % len_str(base);
	res[i] = base[temp_nb];
	if (sign == 1)
	{
		res[i + 1] = '-';
		i++;
	}
	res[i + 1] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	res;
	char		*res_convert;

	if (base_valide(base_to) == 0)
		return (0);
	res_convert = malloc(sizeof(char) * 340);
	if (!res_convert)
		return (0);
	res = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(res, base_to, res_convert);
	invert_tab(res_convert);
	return (res_convert);
}

int	main(int argc, char **argv)
{
	char *res;

	res = ft_convert_base("7894545646", "012345789", "012345789");
	printf("%s\n", res);
	free(res);
	// if (argc == 4)
	// {
	// 	res = ft_convert_base(argv[1], argv[2], argv[3]);
	// 	printf("argc,argv :%s\n", res);
	// 	free(res);
	// }
	(void)argc;
	(void)argv;
	return (0);
}