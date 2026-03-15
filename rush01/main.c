/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:56:58 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/28 23:30:36 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	init_tab(char *tab_char);

int	main(int argc, char **argv)
{
	// init_tab("0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0");
	// init_tab("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 4");
	// init_tab("1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4");
	// init_tab("1 2 3 2 3 2 1 2 1 2 2 2 4 1 3 2");
	init_tab("1 2 2 3 2 1 3 2 1 3 3 2 3 2 1 3 5");
	// test(tab);
	(void)argc;
	(void)argv;
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	init_tab(argv[1]);
// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }
