/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:24:40 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/05 22:21:53 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_lenstr(char *str);
void	ft_putstr(char *str);
void	print_erreur(char *str);
char	**read_and_create_tab(char *dest_dico);
void	put_only_char(char *str);
void	free_malloc(char **str);
char	**split(char *number_enter);
void	print_number_letter(char *number_choice, char **dico_number);

void	print_number_zero(char *str, int index, char **dico_number)
{
	int		i;
	char	*res;

	i = 1;
	if (index >= 5)
	{
		index = index - 2;
	}
	res = malloc((sizeof(char) * ft_lenstr(str) + 50) + 1);
	res[0] = '1';
	while (i < index)
	{
		res[i] = '\0';
		res[i] = '0';
		i++;
	}
	res[i] = '\0';
	if (index % 3 == 1 || ft_lenstr(str) - index <= 3)
		print_number_letter(res, dico_number);
	free(res);
}

void	print_number_two(char *str, char **dico_number)
{
	char	*res;
	int		len;

	len = 0;
	while (str[len])
		len++;
	res = malloc((sizeof(char) * 2) + 1);
	res[0] = str[len - 2];
	res[1] = '0';
	res[3] = '\0';
	print_number_letter(res, dico_number);
	free(res);
}

void	print_all_number(char **dico_number, char **number, char *number_enter)
{
	int	i;
	int	len;

	len = ft_lenstr(number_enter);
	i = 0;
	while (number[i][0] == '0')
	{
		i++;
		len--;
	}
	while (number[i])
	{
		if (len > 2 && number[i][0] != '0' && number[i][0] != '1')
			print_number_letter(number[i], dico_number);
		if (len > 2)
			print_number_zero(number_enter, len, dico_number);
		if (len == 1)
			print_number_two(number_enter, dico_number);
		len--;
		i++;
	}
	print_number_letter(number[ft_lenstr(number_enter) - 1], dico_number);
}

void	cut_number(char **dico_number, char **number, char *number_enter)
{
	int	len;

	len = ft_lenstr(number_enter);
	print_all_number(dico_number, number, number_enter);
}

int	main_print_number_letter(char *number_enter, char *name_dic)
{
	char	**dico_number;
	char	**number;
	int		len;

	len = ft_lenstr(number_enter);
	number = split(number_enter);
	dico_number = read_and_create_tab(name_dic);
	cut_number(dico_number, number, number_enter);
	free_malloc(number);
	free_malloc(dico_number);
	return (1);
}
