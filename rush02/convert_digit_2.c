/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_digit_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:35:05 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/05 22:22:30 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lenstr(char *str);
void	put_only_char(char *str);
void	print_erreur(char *str);

int	find_line_number(char *number_choice, char **dico_number)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (dico_number[i])
	{
		b = 0;
		a = 0;
		while (dico_number[i][a] == number_choice[b] && number_choice[b])
		{
			b++;
			a++;
			if (a == ft_lenstr(number_choice))
				return (i);
		}
		i++;
	}
	return (-1);
}

void	print_number_letter(char *number_choice, char **dico_number)
{
	int	line;

	line = find_line_number(number_choice, dico_number);
	if (line == -1)
	{
		print_erreur("erreur number not find");
		return ;
	}
	put_only_char(dico_number[line]);
}
