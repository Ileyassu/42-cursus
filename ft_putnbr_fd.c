/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 22:02:30 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	nbr;
	int		filedescriptor;

	nbr = n;
	filedescriptor = fd;
	if (n < 0)
	{
		ft_putchar_fd('-', filedescriptor);
		nbr *= -1;
	}
	if (nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', filedescriptor);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, filedescriptor);
		ft_putnbr_fd(nbr % 10, filedescriptor);
	}
}
