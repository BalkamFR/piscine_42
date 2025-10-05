/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:49:59 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/05 14:03:08 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 691

void	ft_putchar(char c);
void	all_null_malloc(char *str);

int	count_line_files(char *dico_number_brut)
{
	int	i;
	int	compt;

	compt = 0;
	i = 0;
	while (dico_number_brut[i])
	{
		if (dico_number_brut[i] == '\n')
			compt++;
		i++;
	}
	return (compt);
}

int	count_len_line(char *dico_number_brut, int line)
{
	int	i;
	int	compt;
	int	compt_len;

	compt_len = 0;
	compt = 0;
	i = 0;
	while (dico_number_brut[i])
	{
		if (dico_number_brut[i] == '\n')
			compt++;
		if (compt == line)
			compt_len++;
		i++;
	}
	return (compt_len);
}

void	add_data_number(char **dico_number, char *dico_number_brut)
{
	int	b;
	int	a;
	int	i;

	a = 0;
	b = 0;
	i = 0;
	while (dico_number[i])
	{
		while (dico_number_brut[a] != '\n' && dico_number_brut[a])
		{
			dico_number[i][b] = '\0';
			dico_number[i][b] = dico_number_brut[a];
			a++;
			b++;
		}
		dico_number[i][b] = '\0';
		// printf("tab[%d] len(%d) data(%s) \n", i,
		// 	count_len_line(dico_number_brut, i), dico_number[i]);
		b = 0;
		a++;
		i++;
	}
}

char	**create_tab(char *dico_number_brut)
{
	int		i;
	int		line_tab;
	char	**dico_number;

	i = 0;
	line_tab = count_line_files(dico_number_brut);
	dico_number = malloc((sizeof(char *) * line_tab) + 1);
	if (!dico_number)
		return (0);
	while (i < line_tab)
	{
		dico_number[i] = malloc(sizeof(char) * (count_len_line(dico_number_brut, i) + 2) + 1);
		all_null_malloc(dico_number[i]);
		if (!dico_number[i])
			return (0);
		i++;
	}
	dico_number[i] = NULL;
	add_data_number(dico_number, dico_number_brut);
	return (dico_number);
}
char	**read_and_create_tab(char *dest_dico)
{
	int		fd1;
	char	**dico_number;
	int		nb_read;
	char	dico_number_brut[BUFFER_SIZE + 1];

	fd1 = open(dest_dico, O_RDONLY);
	if (fd1 == -1)
		return (0);
	nb_read = read(fd1, dico_number_brut, BUFFER_SIZE);
	if (nb_read == -1)
	{
		printf("Erreur de lecture !\n");
		return (0);
	}
	dico_number_brut[nb_read] = '\0';
	dico_number = create_tab(dico_number_brut);
	close(fd1);
	return (dico_number);
}
