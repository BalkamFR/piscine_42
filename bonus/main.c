/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:12:10 by thdervau          #+#    #+#             */
/*   Updated: 2025/09/21 22:25:34 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
void	rush(int x, int y, char *charset);

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	resultat;
	int	char_int;
	int	sign;

	i = 0;
	sign = 1;
	while (ft_is_space(str[i]) || str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	resultat = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			break ;
		char_int = str[i] - '0';
		resultat = (resultat * 10) + char_int;
		i++;
	}
	return (resultat * sign);
}

void	ft_putstr(char *str, int error_code)
{
	while (*str)
	{
		write(error_code, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc > 1 && argc < 5)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (ft_strlen(argv[3]) != 6)
		{
			ft_putstr("error : argument 3 has more or less 6 characters\n", 2);
			return (1);
		}
		rush(x, y, argv[3]);
	}
	return (0);
}
