/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:16:57 by rxue              #+#    #+#             */
/*   Updated: 2024/11/18 17:05:47 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s != (unsigned char)c)
			s++;
		else
			return ((char *)s);
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <assert.h>
int	main(void)
{
	char	s[] = "abcde";

	assert(ft_strchr(s, 'a' + 256) == s);
	return (0);
}*/
