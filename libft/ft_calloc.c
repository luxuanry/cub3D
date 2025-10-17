/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:02:15 by rxue              #+#    #+#             */
/*   Updated: 2024/11/19 16:22:36 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	len;

	len = nmemb * size;
	if (nmemb != 0 && len / nmemb != size)
		return (NULL);
	tmp = malloc(len);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, len);
	return (tmp);
}
