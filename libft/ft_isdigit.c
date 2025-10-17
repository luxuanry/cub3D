/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:16:24 by rxue              #+#    #+#             */
/*   Updated: 2024/11/06 16:06:24 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char	c;

	c = 'c';
	if (ft_isdigit(c) == 0)
		printf("%c is not a digit.\n", c);
	else
		printf("%c is a digit.\n", c);
	return (0);
}*/
