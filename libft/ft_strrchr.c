/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:26:44 by rxue              #+#    #+#             */
/*   Updated: 2024/11/18 17:06:06 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		ptr = (char *)s;
	return (ptr);
}
/*
#include <assert.h>
int	main(void)
{
	char	*s = "abcde";

	assert(ft_strrchr(s, 'a' + 256) == s);
	return (0);
}*/
