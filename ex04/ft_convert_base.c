/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:14:49 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/07 16:32:04 by papilaz          ###   ########.fr       */
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

int	check_number_valide(char *nbr, char *base)
{
	int	len_nbr;
	int	len;
	int	i;
	int	a;

	a = 0;
	len = 0;
	i = 0;
	while ((nbr[a] >= 9 && nbr[a] <= 13) || (nbr[a] == 32 || nbr[a] == '-' || nbr[a] == '+'))
		a++;
	len_nbr = len_str(nbr + a);
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
	if (len == len_nbr)
		return (1);
	return (0);
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
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	len_base = len_str(base);
	while (str[i])
	{
		res = res * len_base + convert_value(str[i], base);
		i++;
	}
	return (res);
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

char	*ft_putnbr_base(int nb, char *base, char *res)
{
	int	len_base;
	int	temp_nb;
	int	i;

	i = 0;
	temp_nb = 0;
	len_base = len_str(base);
	while (len_base <= nb)
	{
		temp_nb = nb % len_base;
		res[i] = base[temp_nb];
		nb = nb / len_base;
		i++;
	}
	temp_nb = nb % len_base;
	res[i] = base[temp_nb];
	res[i + 1] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		res;
	char	*res_convert;

	if (base_valide(base_to) == 0 || check_number_valide(nbr, base_from) == 0)
		return (0);
	res_convert = malloc(sizeof(char) * 5000);
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

	res = ft_convert_base("5", "0123456789", "01");
	printf("%s\n", res);
	free(res);
	res = ft_convert_base("d", "a", "0123456789");
	printf("%s\n", res);
	free(res);
	res = ft_convert_base("78", "79", "01");
	printf("%s\n", res);
	free(res);
	if (argc == 4)
	{
		res = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("argc,argv :%s\n", res);
		free(res);
	}

	return (0);
}