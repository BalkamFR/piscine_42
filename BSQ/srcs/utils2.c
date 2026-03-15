/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:11:13 by equentin          #+#    #+#             */
/*   Updated: 2025/10/08 15:37:23 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (nb);
}

void	ft_print(char *str, int out)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(out, str, i);
}
