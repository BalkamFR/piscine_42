/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:28:34 by papilaz           #+#    #+#             */
/*   Updated: 2025/09/21 13:05:17 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char str)
{
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z') || (str >= '0'
			&& str <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (ft_str_is_lowercase(str[i]) == 1)
		{
			if (ft_str_is_alpha(str[i - 1]) == 0)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "hi,how are you? 42words forty-t
//wo; fifty+and+oneRekt17+Lol MDr";

// 	printf("%s\n", src);
// 	ft_strcapitalize(src);
// 	printf("%s\n", src);
// }