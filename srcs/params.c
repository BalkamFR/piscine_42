/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:33:08 by equentin          #+#    #+#             */
/*   Updated: 2025/10/07 20:54:04 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/params.h"
#include "../includes/utils.h"

void	write_params(t_params *params, char **map)
{
	int	params_len;

	params_len = ft_strlen(map[0]);
	params->full = map[0][params_len - 1];
	params->block = map[0][params_len - 2];
	params->empty = map[0][params_len - 3];
	map[0][params_len - 3] = '\0';
	params->size = ft_atoi(map[0]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:04:47 by equentin          #+#    #+#             */
/*   Updated: 2025/09/30 18:47:12 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_nul_byte(char *str, int s)
{
	while (s-- > 0)
		str[s] = '\0';
}

int	is_base_valid(char *base)
{
	int	lenght;
	int	i;
	int	j;

	lenght = 0;
	while (base[lenght])
		lenght++;
	if (lenght < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
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

char	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

void	skip_whitespace(char *str, int *i, char *multiplier)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*multiplier *= -1;
		*i += 1;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		i;
	char	multiplier;
	int		lenght_base;
	int		index_base;

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
		index_base = is_in_base(str[i], base);
		if (index_base == -1)
			break ;
		nb = nb * lenght_base + index_base;
		i++;
	}
	return (nb * multiplier);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:08:24 by equentin          #+#    #+#             */
/*   Updated: 2025/10/06 16:16:19 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		is_base_valid(char *base);
int		ft_atoi_base(char *str, char *base);
void	fill_nul_byte(char *str, int s);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	write_min_base(unsigned int n, char *b, unsigned int l_b, char *c_nb)
{
	int	l;

	l = ft_strlen(c_nb);
	if (n < l_b)
	{
		c_nb[l] = b[n % l_b];
		return ;
	}
	else
	{
		write_min_base(n / l_b, b, l_b, c_nb);
		write_min_base(n % l_b, b, l_b, c_nb);
	}
}

void	ft_putnbr_base(int nbr, char *base, int lenght_base, char *c_nb)
{
	int	l;

	l = ft_strlen(c_nb);
	if (nbr == -2147483648)
	{
		c_nb[l] = '-';
		return (write_min_base(-nbr, base, lenght_base, c_nb));
	}
	else if (nbr < 0)
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

void	ft_strcpy_free(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	dest[i] = '\0';
}

/*
malloc 34 -> sign + 32 (max lenght for a base 2) + NUL byte
*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*c_nb;
	char	*f_nb;
	int		base_from_lenght;
	int		base_to_lenght;

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
	ft_strcpy_free(f_nb, c_nb);
	return (f_nb);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*s;

	if (argc != 4)
		return (0);
	s = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s", s);
	free(s);
	return (0);
}
