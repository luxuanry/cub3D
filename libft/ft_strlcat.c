/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:21:56 by rxue              #+#    #+#             */
/*   Updated: 2024/11/19 16:30:03 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlcat_strlen_max(const char *s, size_t max_len)
{
	size_t	len;

	len = 0;
	while (len < max_len && s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t			dst_initial_len;
	unsigned long	src_index;

	dst_initial_len = ft_strlcat_strlen_max(dst, siz);
	src_index = 0;
	while (dst_initial_len + src_index + 1 < siz && src[src_index] != '\0')
	{
		dst[dst_initial_len + src_index] = src[src_index];
		src_index++;
	}
	if (dst_initial_len + src_index < siz)
		dst[dst_initial_len + src_index] = '\0';
	return (dst_initial_len + ft_strlen(src));
}
/*
#include <assert.h>
int	main(void)
{
	char	s[] = {'a', 'b', 'c', 'd', 'e', '\0', '\0', '\0','\0'};
	char	s1[] = {'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', '\0'};

	ft_strlcat(s, s, 9);
	assert(memcmp(s, s1, 9) == 0);
	return (0);
}*/
