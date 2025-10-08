/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papilaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:13:06 by papilaz           #+#    #+#             */
/*   Updated: 2025/10/08 23:31:34 by papilaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	srt_len(char c, char *str, int flag)
{
	if (flag == 0)
	{
		if (!str[flag])
			return (1);
		while (str[flag])
			flag++;
		return (flag - 1);
	}
	if (flag == 2)
	{
		while (*str)
		{
			if (c == *str)
				return (1);
			str++;
		}
	}
	while (*str && flag == 3)
	{
		if (*str == c)
			return (4);
		str++;
	}
	return (0);
}

int	compt_all_word(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str && srt_len(*str, charset, 3) == 0)
			str++;
		if (*str && srt_len(*str, charset, 3) != 0)
		{
			len++;
			while (srt_len(*str, charset, 3) != 0 && *str)
				str++;
		}
		str++;
	}

	return (len);
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
		while (srt_len(str[i], charset, 2) == 1)
			i++;
		while (srt_len(str[i], charset, 2) == 0)
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

void	add_data(char **tab_all, char *str, char *charset)
{
	int	i;
	int	a;

	i = 0;
	if (charset[0] == '\0')
	{
		tab_all[0] = str;
		tab_all[1] = NULL;
		return ;
	}
	while (0 < compt_all_word(str, charset))
	{
		a = 0;
		while (srt_len(*str, charset, 2) == 0)
		{
			tab_all[i][a] = *str;
			str++;
			a++;
		}
		tab_all[i][a] = '\0';
		while (srt_len(*str, charset, 2) == 1)
			str++;
		i++;
	}
	tab_all[i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**tab_all;
	int		i;

	i = 0;
	tab_all = malloc(sizeof(char *) * (compt_all_word(str, charset) + 1));
	if (!tab_all)
		return (0);
	while (i < compt_all_word(str, charset) - (srt_len('c', charset, 0)))
	{
		tab_all[i] = malloc((sizeof(char) * len_word(str, charset, i) + 1));
		if (!tab_all[i])
			return (0);
		i++;
	}
	if (i == 0)
	{
		tab_all[0] = malloc((sizeof(char) * (srt_len('c', str, 0) + 1)));
		tab_all[0][i] = '\0';
	}
	add_data(tab_all, str, charset);
	return (tab_all);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split("j aime le caca", " a");
	while (tab[i])
	{
		printf("tab[%d] : %s\n", i, tab[i]);
		i++;
	}
	printf("%p\n", tab[i]);

	free(tab);
	(void)argc;
	(void)argv;
	return (0);
}