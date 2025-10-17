/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:47:42 by rxue              #+#    #+#             */
/*   Updated: 2024/11/13 16:36:30 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_unsafe_overlap(const void *dest, const void *src, size_t n)
{
	const char	*a_dest;
	const char	*a_src;

	a_dest = dest;
	a_src = src;
	return (a_src < a_dest && a_dest <= a_src + n);
}

static void	*memcpy_reverse(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[n - i - 1] = ((unsigned char *)src)[n - i - 1];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (has_unsafe_overlap(dest, src, n))
		return (memcpy_reverse(dest, src, n));
	else
		return (ft_memcpy(dest, src, n));
}
/*
#include <assert.h>
int	main(void)
{
	char	s[] = {'a', 'b', 'c', 'd', 'e'};
	char	s1[] = {'a', 'b', 'a', 'b', 'c'};

	ft_memmove(s + 2, s, 3);
	assert(memcmp(s, s1, 5) == 0);
	return (0);
}*/
