/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:33:44 by rxue              #+#    #+#             */
/*   Updated: 2024/11/14 16:19:50 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*uc_s;
	unsigned char			uc_c;

	i = 0;
	uc_s = s;
	uc_c = c;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
			return ((void *)(uc_s + i));
		i++;
	}
	return (NULL);
}
/*
#include <assert.h>
int	main(void)
{
	char	s[] = {0, 1, 2, 3, 4, 5};

	assert(ft_memchr(s, 0, 0) == NULL);
	assert(ft_memchr(s, 0, 1) == s);
	assert(ft_memchr(s, 2, 3) == s + 2);
	assert(ft_memchr(s, 6, 6) == NULL);
	assert(ft_memchr(s, 2 + 256, 3) == s + 2);
	return (0);
}*/
