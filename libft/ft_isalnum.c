/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:55:33 by rxue              #+#    #+#             */
/*   Updated: 2024/11/06 16:06:52 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = '5';
	if (ft_isalnum(c) == 0)
		printf("%c is not an alphabet nor a digit.\n", c);
	else
		printf("%c is an alphabet or a digit.\n", c);
	return (0);
}*/
