/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:01:37 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/08 16:18:13 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	is_base_valid(char *base);
long int	ft_atoi_base(char *str, char *base);
void		fill_nul_byte(char *str, int s);

long int	ft_strlen(char *str)
{
	long int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base(long int nbr, char *base, long int lenght_base,
		char *c_nb)
{
	long int	l;

	l = ft_strlen(c_nb);
	if (nbr < 0)
	{
		c_nb[l] = '-';
		ft_putnbr_base(-nbr, base, lenght_base, c_nb);
	}
	else if (nbr < lenght_base)
		c_nb[l] = base[nbr % lenght_base];
	else
	{
		ft_putnbr_base(nbr / lenght_base, base, lenght_base, c_nb);
		ft_putnbr_base(nbr % lenght_base, base, lenght_base, c_nb);
	}
}

void	all_free(char *dest, char *src)
{
	long int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	dest[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*c_nb;
	char		*f_nb;
	long int	base_from_lenght;
	long int	base_to_lenght;

	c_nb = malloc(sizeof(char) * 34);
	if (c_nb == NULL)
		return (NULL);
	fill_nul_byte(c_nb, 34);
	base_from_lenght = is_base_valid(base_from);
	base_to_lenght = is_base_valid(base_to);
	if (base_from_lenght == 0 || base_to_lenght == 0)
	{
		free(c_nb);
		return (NULL);
	}
	ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to, base_to_lenght, c_nb);
	f_nb = malloc((sizeof(char) * ft_strlen(c_nb) + 1));
	if (f_nb == NULL)
	{
		free(c_nb);
		return (NULL);
	}
	all_free(f_nb, c_nb);
	return (f_nb);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*s;

// 	if (argc != 4)
// 		return (0);
// 	s = ft_convert_base(argv[1], argv[2], argv[3]);
// 	printf("%s", s);
// 	free(s);
// 	return (0);
// }