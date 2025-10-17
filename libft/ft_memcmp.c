/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:24:07 by rxue              #+#    #+#             */
/*   Updated: 2024/11/14 16:46:11 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	i = 0;
	uc_s1 = s1;
	uc_s2 = s2;
	while (i < n)
	{
		if (uc_s1[i] != uc_s2[i])
			return (uc_s1[i] - uc_s2[i]);
		i++;
	}
	return (0);
}
/*
#include <assert.h>
int	main(void)
{
	char	s[] = {-128, 0, 127, 0};
	char	sCpy[] = {-128, 0, 127, 0};
	char	s2[] = {0, 0, 127, 0};
	char	s3[] = {0, 0, 42, 0};
	assert(ft_memcmp(s, sCpy, 4) == 0);
	assert(ft_memcmp(s, s2, 0) == 0);
	assert(ft_memcmp(s, s2, 1) > 0);
	assert(ft_memcmp(s2, s, 1) < 0);
	assert(ft_memcmp(s2, s3, 4) > 0);
	return (0);
}*/
