/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:49:59 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/04 15:09:38 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 5020

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	create_tab(char *dico_number, int nbr)
{
	int	i;
	int	compt;

	compt = 0;
	i = 0;
	while (dico_number[i])
	{
		if (dico_number[i] == '\n')
			compt++;	
		if (compt == nbr && dico_number[i] != '\n')
		{
			ft_putchar(dico_number[i]);
		}
		i++;
	}
}
void	read_and_print_100(int fd, int nbr)
{
	char dico_number[BUFFER_SIZE + 1]; 
	int nb_read;                 
	nb_read = read(fd, dico_number, BUFFER_SIZE);
	if (nb_read == -1)
	{
		printf("Erreur de lecture !\n");
		return ;
	}
	dico_number[nb_read] = '\0';
	create_tab(dico_number, nbr);
	return ;
}

int	main(int argc, char **argv)
{
	int fd1;

	fd1 = open("numbers.dict", O_RDONLY);
	if (fd1 == -1)
		return (1);
	read_and_print_100(fd1, atoi(argv[1]));
	ft_putchar('\n');
	close(fd1);
	return (0);
}