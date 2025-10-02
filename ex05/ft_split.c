/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:13:06 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/02 16:59:59 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	compt_word(char *str, char charset)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == charset)
			i++;
		if (str[i])
		{
			while (str[i] != charset && str[i])
				i++;
			len++;
		}
	}
	return (len);
}

int	compt_all_word(char *str, char *charset)
{
	int	i;
	int	compt;

	compt = 0;
	i = 0;
	while (charset[i])
	{
		compt = compt_word(str, charset[i]) + compt;
		i++;
	}
	return (compt);
}

int	charsetverif(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	len_word(char *str, char *charset, int index)
{
	int	i;
	int	len;
	int	compt;

	i = 0;
	len = 0;
	compt = 0;
	while (str[i])
	{
		compt = 0;
		while (charsetverif(str[i], charset) == 1)
			i++;
		while (charsetverif(str[i], charset) == 0)
		{
			compt++;
			i++;
		}
		if (len == index)
			return (compt);
		len++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab_all;
	int		i;
	int		a;

	i = 0;
	tab_all = malloc((sizeof(char *) * compt_all_word(str, charset)) + 1);
	while (i < compt_all_word(str, charset))
	{
		tab_all[i] = malloc((sizeof(char) * len_word(str, charset, i)) + 1);
		i++;
	}
	i = 0;
	while (tab_all[i])
	{
		a = 0;
		while (charsetverif(*str, charset) == 0)
		{
			tab_all[i][a] = *str;
			str++;
			a++;
		}
		while (charsetverif(*str, charset) == 1)
			str++;
		i++;
	}
	tab_all[i] = NULL;
	return (tab_all);
}

// int	main(int argc, char **argv)
// {
// 	int i;
// 	char **tab;
// 	char *str;
// 	char *charset;

// 	i = 0;
// 	charset = "- ";
// 	str = "c-omment ca va ?";
// 	tab = ft_split(str, charset);

// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }

int	main(void)
{
	printf("%d", compt_all_word("comm-en-t tu va ?", " -"));
}