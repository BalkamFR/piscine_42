/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:35:09 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/29 10:31:58 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// int	verif_tab(char *str)
// {
// 	int	i;
// 	int	a;
// 	int	len;

// 	a = 0;
// 	len = 0;
// 	i = 0;
// 	while (str[len])
// 		len++;
// 	while (str[i])
// 	{
// 		a = i + 1;
// 		while (a <= len)
// 		{
// 			if (str[a] == str[i])
// 				return (0);
// 			a++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	len_str(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	char_askii(char c)
// {
// 	int	i;

// 	i = c;
// 	if (c >= '0' && c <= '9')
// 		return (c - '0');
// 	return (i);
// }

// int	int_base(int nb, char *base)
// {
// 	int	len_base;
// 	int	temp_nb;
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	temp_nb = 0;
// 	len_base = len_str(base);
// 	while (len_base <= nb && nb != 0)
// 	{
// 		temp_nb = nb % len_base;
// 		res = res * 10;
// 		res = (base[temp_nb] - '0') + res;
// 		nb = nb / len_base;
// 		i++;
// 	}

// 	return (res);
// }

// // int	ft_atoi_base(char *str, char *base)
// // {
// // 	int	res;
// // 	int	i;

// // 	return (res);
// // }

// int	main(void)
// {
// 	int	i;

// 	i = 256;
// 	while (i < 1024)
// 	{
// 		printf("%d\n", int_base(i, "1234"));
// 		printf("%d\n", int_base(i, "2341"));
// 		printf("%d\n", int_base(i, "3412"));
// 		printf("%d\n\n", int_base(i, "4123"));
// 		i++;
// 	}

// }
