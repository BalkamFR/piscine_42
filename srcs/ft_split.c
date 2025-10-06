/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 08:00:12 by equentin          #+#    #+#             */
/*   Updated: 2025/10/06 11:03:12 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	should_split(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	c;
	int	i;
	int	s;

	c = 0;
	i = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if (should_split(str[i], charset))
			s = 1;
		else if (s == 1)
		{
			s = 0;
			c++;
		}
		i++;
	}
	if (i > 0 && !should_split(str[0], charset))
		c++;
	return (c);
}

int	strcpy_split(char *str, char *charset, char **strs, int start)
{
	int	i;
	int	j;
	int	end;

	while (should_split(str[start], charset))
		start++;
	end = 0;
	while (!should_split(str[start + end], charset) && str[start + end])
		end++;
	i = 0;
	while (strs[i] != NULL)
		i++;
	strs[i] = malloc(sizeof(char) * (end + 1));
	if (strs[i] == NULL)
		return (-1);
	j = 0;
	while (j < end)
	{
		strs[i][j] = str[start + j];
		j++;
	}
	strs[i][j] = '\0';
	return (start + end);
}

char	**ft_split(char *str, char *charset)
{
	int		c_words;
	int		i;
	int		start;
	char	**strs;

	c_words = count_words(str, charset);
	strs = malloc(sizeof(char *) * (c_words + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (i < c_words)
	{
		strs[i++] = NULL;
		start = strcpy_split(str, charset, strs, start);
		if (start == -1)
			return (NULL);
	}
	strs[i] = NULL;
	return (strs);
}
