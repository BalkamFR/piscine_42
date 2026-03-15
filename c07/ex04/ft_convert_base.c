/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:01:34 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/08 16:18:32 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_strlen(char *str);

void	fill_nul_byte(char *str, int s)
{
	while (s-- > 0)
		str[s] = '\0';
}

long int	is_base_valid(char *base)
{
	long int	lenght;
	long int	i;
	long int	j;

	lenght = 0;
	while (base[lenght])
		lenght++;
	if (lenght < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9
				&& base[i] <= 13))
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (lenght);
}

char	check_base(char c, char *base)
{
	long int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

void	skip_whitespace(char *str, long int *i, char *multiplier)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*multiplier *= -1;
		*i += 1;
	}
}

long int	ft_atoi_base(char *str, char *base)
{
	long int	nb;
	long int	i;
	char		multiplier;
	long int	lenght_base;
	long int	index_base;

	lenght_base = is_base_valid(base);
	if (lenght_base == 0)
		return (0);
	nb = 0;
	i = 0;
	multiplier = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	skip_whitespace(str, &i, &multiplier);
	while (str[i])
	{
		index_base = check_base(str[i], base);
		if (index_base == -1)
			break ;
		nb = nb * lenght_base + index_base;
		i++;
	}
	return (nb * multiplier);
}
