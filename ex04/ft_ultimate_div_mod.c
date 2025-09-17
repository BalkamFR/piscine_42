/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:00:33 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/17 14:07:23 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_ultimate_div_mod(int *a, int *b)
{
	int	res;
	int	rest;
	
	res = (*a / *b);
	rest = (*a % *b);
	
	*a = res;
	*b = rest;
}

#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	
	a = 11;
	b = 2;


	ft_ultimate_div_mod(&a, &b);
	printf("resultat : %d\nrest : %d \n", a, b);
}