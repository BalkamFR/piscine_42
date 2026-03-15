/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushBonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:50:12 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 22:28:56 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	put_line(int x, char left, char middle, char right);
void	rush(int x, int y, char *charset);

void	put_line(int x, char left, char middle, char right)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			write(1, &left, 1);
		else if (i == x - 1)
			write(1, &right, 1);
		else
			write(1, &middle, 1);
		i++;
	}
}
/* charset
	[0 = horizontal ;  1 = vertical]
	[2 = topleft ; 3 = topright]
	[4 = botleft ; 5 = botright]
*/

void	rush(int x, int y, char *charset)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			put_line(x, charset[2], charset[0], charset[3]);
		else if (i == y - 1)
			put_line(x, charset[4], charset[0], charset[5]);
		else
			put_line(x, charset[1], ' ', charset[1]);
		write(1, "\n", 1);
		i++;
	}
}
