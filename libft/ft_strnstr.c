/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:52:51 by rxue              #+#    #+#             */
/*   Updated: 2024/11/26 18:01:11 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	if (little && !ft_strlen(little))
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	big_len = ft_strlen(big);
	if (big_len < len)
		len = big_len;
	little_len = ft_strlen(little);
	i = 0;
	while (i < len)
	{
		if (i + little_len > len)
			return (0);
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*	unsigned int	i;
	size_t			little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!little)
		return ((char *)big);
	while (i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}*/
/*
#include <assert.h>
int	main(void)
{
	char	*big = "testing foo testing foo";
//	puts(ft_strnstr(big, "foo", 0));
	assert(ft_strnstr(big, "foo", 0) == NULL);
//	assert(ft_strnstr(big, "", 23) == big);
//	assert(ft_strnstr(big, "foo", 10) == NULL);
	return (0);
}*/
