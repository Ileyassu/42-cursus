/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:21 by ilyas             #+#    #+#             */
/*   Updated: 2024/02/06 21:27:33 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../printf/ft_printf.h"
# include "../getnextline/get_next_line.h"

int		unsigned_putnbr(unsigned int nbr);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putaddr(void *ptr);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(unsigned long n, int base, int uppercase);
int		count_digits(unsigned int nb);
#endif
