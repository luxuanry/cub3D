/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:09:51 by rxue              #+#    #+#             */
/*   Updated: 2024/11/06 15:10:53 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main()
{
	char	c;

	c = '5';
	if (ft_isalpha(c) == 0)
		printf("%c is not an alphabet.\n", c);
	else
		printf("%c is an alphabet.\n", c);
	return (0);
}*/
