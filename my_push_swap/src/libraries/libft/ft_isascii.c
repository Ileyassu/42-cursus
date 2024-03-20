/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:03 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/20 16:49:54 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	else
	{
		return (0);
	}
}
/*
int main() {
    int currentChar;

    printf("ktb chi haja wla chi haja (Ctrl+D on Unix/Linux):\n");

    while ((currentChar = getchar()) != EOF) {
        if (ft_isascii(currentChar) == 1) {
            printf("'%c' is ascii.\n", currentChar);
        } else if (ft_isascii(currentChar) == 0) {
            printf("'%c' is not ascii.\n", currentChar);
        }
    }

    return 0;
}
*/