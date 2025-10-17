/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:59:57 by rxue              #+#    #+#             */
/*   Updated: 2024/11/12 16:41:12 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)s;
	while (n)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}
/*
#include <assert.h>
#include <strings.h>
int	main(void)
{
	char	dst[10] = "abcdefg";
	char	dst1[10] = "bgsfeaeg";
	char	dst_goal[] = {'\0', '\0', '\0', '\0', '\0', 
	'\0', '\0', '\0', '\0', '\0'};

	ft_bzero(dst, sizeof(dst));
	assert(memcmp(dst, dst_goal, sizeof(dst)) == 0);
	bzero(dst1, sizeof(dst1));
	assert(memcmp(dst, dst1, sizeof(dst)) == 0);

	return (0);
}*/
