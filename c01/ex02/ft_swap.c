/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:45:27 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/19 10:16:14 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temps;

	temps = *b;
	*b = *a;
	*a = temps;
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 42;
// 	b = 69;

// 	printf("avant a : %d\navant b : %d\n\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("apres a : %d\napres b : %d\n", a, b);
// }