/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:42:00 by rxue              #+#    #+#             */
/*   Updated: 2024/11/26 15:23:24 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	while (is_space(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1);
	while (end > 0 && is_space(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
int main (void)
{
	char *s = "xxxx  hellllllooxx  x";
	puts(ft_strtrim(s, " x"));
	return (0);
}*/
