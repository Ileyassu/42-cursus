#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
int ft_putchar(int c);
int ft_putstr(char *s);
int ft_putnbr(int n);
void printaddress(void *ptr);
void ft_putnbr_base(long nbr, char *base, int count);
int	ft_printf(const char *s, ...);
char	*ft_strchr(const char *str, int c);

#endif
