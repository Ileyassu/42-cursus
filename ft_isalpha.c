/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:00 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/19 13:09:26 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(const int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
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
        if (ft_isalpha(currentChar) == 1) {
            printf("'%c' is alphabetic.\n", currentChar);
        } else if (ft_isalpha(currentChar) == 0) {
            printf("'%c' is not alphabetic.\n", currentChar);
        }
    }

    return 0;
}
*/
