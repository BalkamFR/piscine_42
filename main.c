/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:06:05 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/05 13:32:55 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	main_print_number_letter(char *number_enter, char *name_dic);


int	main(int argc, char **argv)
{
	// char **tab;
	int i;
	char *name_dic;

	name_dic = "dicofr.dict";
	// name_dic = "numbers.dict";

	// i = 0;
	// tab = read_and_create_tab("numbers.dict");
	// while (tab[i])
	// {
	// 	ft_putstr("\n");
	// 	ft_putstr(tab[i]);
	// 	i++;
	// }
	// ft_putchar(tab[i][4]);

	i = main_print_number_letter(argv[1], name_dic);
	if (i != 0)
	{
		return(0);
	}
	
	ft_putchar('\n');
	(void)argc;
	(void)argv;
	return (0);
}