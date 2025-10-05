/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:06:05 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/05 22:25:10 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		main_print_number_letter(char *number_enter, char *name_dic);
void	print_erreur(char *str);

int	main(int argc, char **argv)
{
	int		i;
	char	*name_dic;

	if (argc == 2)
	{
		name_dic = "numbers.dict";
		i = main_print_number_letter(argv[1], name_dic);
	}
	if (argc == 3)
		i = main_print_number_letter(argv[1], argv[2]);
	if (argc == 1)
		print_erreur("Error\n");
	if (i != 0)
		return (0);
	ft_putchar('\n');
	(void)argc;
	(void)argv;
	return (0);
}
