/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:34:00 by rxue              #+#    #+#             */
/*   Updated: 2024/11/06 16:44:14 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 2;
	if (ft_isprint(c) == 0)
		printf("%c is not printable.\n", c);
	else
		printf("%c is printable.\n", c);
	return (0);
}*/
