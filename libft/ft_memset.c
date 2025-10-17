/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:59 by rxue              #+#    #+#             */
/*   Updated: 2024/11/26 16:41:08 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <assert.h>
int	main(void)
{
	char	str[50] = "happy november.";
	ft_memset(str, '-', 5);
	puts(str);

//test_basic
	char	dst1[10];
	char	dst_goal1[] = {'@', '@', '@', '@', '@', '@', '@', '@', '@', '@'};

	assert(ft_memset(dst1, '@', sizeof(dst1)) == dst1);
	assert(memcmp(dst1, dst_goal1, sizeof(dst1)) == 0);

//test_null
	char	dst2[10];
	char	dst_goal2[] = {'\0', '\0', '\0', '\0', '\0', 
	'\0', '\0', '\0', '\0', '\0'};

	assert(ft_memset(dst2, '\0', sizeof(dst2)) == dst2);
	assert(memcmp(dst2, dst_goal2, sizeof(dst2)) == 0);

//test_no_ascii
	char	dst3[10];
	char	dst_goal3[] = {'\x9A', '\x9A', '\x9A', '\x9A', 
	'\x9A', '\x9A', '\x9A', '\x9A', '\x9A', '\x9A'};

	assert(ft_memset(dst3, '\x9A', sizeof(dst3)) == dst3);
	assert(memcmp(dst3, dst_goal3, sizeof(dst3)) == 0);

	return (0);
}*/
