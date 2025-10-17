/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:11 by rxue              #+#    #+#             */
/*   Updated: 2024/12/03 13:28:22 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	strlen_split(const char *s, char c)
{
	int	j;

	j = 0;
	while (*s != c && *s++)
		j++;
	return (j);
}

static int	count_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**result;

	i = 0;
	k = 0;
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		result[k] = malloc(strlen_split(s, c) + 1);
		if (!result[k])
			return (freeall(result), NULL);
		while (*s != c && *s)
			result[k][i++] = *s++;
		result[k++][i] = '\0';
		i = 0;
		while (*s == c && *s)
			s++;
	}
	return (result[k] = NULL, result);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int i;
	char	**test;

	i = 0;
	if (argc < 3)
		return (0);
	test = ft_split(argv[1], argv[2][0]);
	while (test[i] != NULL)
	{
		printf("%s\n", test[i]);
		free(test[i++]);
	}
	free(test);
}*/
