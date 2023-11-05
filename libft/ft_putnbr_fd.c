/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:42:42 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    size_t nbr = n;

    if(nbr < 0)
    {
        ft_putchar_fd('-', 1);
        nbr *= -1;
    }
    if(nbr <= 9)
    {
        ft_putchar_fd(nbr + '0', 1);
    }
    else
    {
        ft_putnbr_fd(nbr / 10, 1);
        ft_putnbr_fd(nbr % 10, 1);
    }
}