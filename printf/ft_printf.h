/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:21 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/30 17:23:54 by ibenaiss         ###   ########.fr       */
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

int		unsigned_putnbr(unsigned int nbr);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putaddr(void *ptr);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *str, int c);
int		ft_putnbr_base(unsigned long n, int base, int uppercase);
size_t	ft_strlen(const char *str);
int		count_digits(unsigned int nb);
#endif
