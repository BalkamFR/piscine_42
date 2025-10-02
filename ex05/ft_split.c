/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:13:06 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/02 16:01:18 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	compt_word(char *str, char charset)
{
	int	i;
	int	len;

	i = 0;
	len = len_str(str);
	while (str[i] != charset)
	{
		if (i == len)
			return (0);
		i++;
	}
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

int	len_word(char *str, char charset, int index)
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
		while (str[i] == charset)
			i++;
		while (str[i] != charset)
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
	int		len_all;
	int		a;

	i = 0;
	tab_all = malloc((sizeof(char *) * compt_all_word(str, charset)) + 1);
	while (i < len_all)
	{
		tab_all[i] = malloc((sizeof(char) * len_word(str, charset[0], i)) + 1);
		i++;
	}
	i = 0;
	len_all = 0;
	while (tab_all[i])
	{
		a = 0;
		while (*str != charset[0])
		{
			tab_all[i][a] = str[len_all];
			len_all++;
			a++;
		}
		tab_all[i][len_all] = '\0';
		while (str[len_all]== charset[0])
			len_all++;
		i++;
	}
	tab_all[i] = NULL;
	return (tab_all);
}

int	main(int argc, char **argv)
{
	int i;
	char **tab;
	char *str;
	char *charset;

	i = 0;
	charset = "-";
	str = "hello-caca";
	tab = ft_split(str, charset);

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	(void)argc;
	(void)argv;
	return (0);
}