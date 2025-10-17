/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:02:27 by rxue              #+#    #+#             */
/*   Updated: 2024/11/22 12:36:46 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
	}
	else
	{
		if (start + len > s_len)
			len = s_len - start;
		sub = (char *)malloc(len + 1);
		if (!sub)
			return (NULL);
		ft_strlcpy(sub, s + start, len + 1);
	}
	return (sub);
}
/*
int main(void)
{
	char *s = ft_substr("hello", 0, 52000);
	puts(s);
	return (0);
}*/
