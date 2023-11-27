/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:21 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/27 14:45:58 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int unsigned_putnbr(unsigned int nbr);
int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int printaddress(unsigned long *n);
int ft_printf(char *str, ...);
char	*ft_strchr(const char *str, int c);
int hexabase(unsigned int nbr);
int ultra_hexabase(unsigned int nbr);
size_t	ft_strlen(const char *str);
int	count_digits(unsigned int nb);
#endif
