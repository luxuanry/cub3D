/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:23:27 by rxue              #+#    #+#             */
/*   Updated: 2024/11/06 16:30:53 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = -1;
	if (ft_isascii(c) == 0)
		printf("%c is not an ASCII character.\n", c);
	else
		printf("%c is an ASCII character.\n", c);
	return (0);
}*/
