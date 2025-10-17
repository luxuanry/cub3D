/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:28:27 by rxue              #+#    #+#             */
/*   Updated: 2024/12/17 18:55:49 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

void	*ft_memcpy1(void *dest, const void *src, int n)
{
	int	i;

	i = 0;
	if ((!dest) || (!src))
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc1(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	i = 0;
	len = nmemb * size;
	if (nmemb != 0 && len / nmemb != size)
		return (NULL);
	tmp = malloc(len);
	if (!tmp)
		return (NULL);
	while (i < nmemb)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dst;

	s1_len = ft_strlen1(s1);
	s2_len = ft_strlen1(s2);
	dst = (char *)malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	ft_memcpy1(dst, s1, s1_len + 1);
	ft_memcpy1(dst + s1_len, s2, s2_len + 1);
	return (dst);
}
