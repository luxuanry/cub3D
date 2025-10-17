/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:44:48 by rxue              #+#    #+#             */
/*   Updated: 2024/11/22 13:04:31 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(int nbr)
{
	unsigned int	n;
	int				i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		n = -nbr;
	}
	else
		n = nbr;
	if (nbr == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_nbr_to_str(int nbr, char *result)
{
	int				i;
	int				len;
	unsigned int	n;

	i = 0;
	len = ft_nbr_len(nbr);
	if (nbr < 0)
	{
		result[0] = '-';
		n = -nbr;
	}
	else
		n = nbr;
	if (nbr == 0)
	{
		result[0] = '0';
		result[1] = '\0';
	}
	while (n > 0)
	{
		result[len - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = ft_nbr_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	result = ft_nbr_to_str(n, result);
	return (result);
}
/*

#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-123));
	return (0);
}*/
