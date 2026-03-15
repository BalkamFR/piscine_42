/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:13:18 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/05 18:41:37 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_erreur(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	put_only_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ')
		i++;
	i++;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putstr(" ");
}
