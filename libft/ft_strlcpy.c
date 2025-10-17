/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:59:30 by rxue              #+#    #+#             */
/*   Updated: 2024/11/13 16:41:53 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < siz)
		ft_memmove(dst, src, src_len + 1);
	else if (siz != 0)
	{
		ft_memmove(dst, src, siz - 1);
		dst[siz - 1] = 0;
	}
	return (src_len);
}
/*
#include <assert.h>
int	main(void)
{
	char	s[] = {'a', 'b', 'c', 'd', 'e'};
	char	s1[] = {'a', 'a', 'b', '\0', 'e'};

	ft_strlcpy(s + 1, s, 3);
	puts(s);
	assert(memcmp(s, s1, sizeof(s)) == 0);
	return (0);
}*/
