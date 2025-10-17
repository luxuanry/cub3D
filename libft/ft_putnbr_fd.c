/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:10:19 by rxue              #+#    #+#             */
/*   Updated: 2024/11/26 16:53:12 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (fd >= 0)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar_fd('-', fd);
		}
		if (nbr > 9)
		{
			ft_putnbr_fd((nbr / 10), fd);
			ft_putnbr_fd((nbr % 10), fd);
		}
		else
			ft_putchar_fd(nbr + '0', fd);
	}
}
