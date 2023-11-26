#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int unsigned_putnbr(unsigned int nbr);
void ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int printaddress(unsigned long *n);
int ft_putnbr_base(long nbr, char *base, int count);
int ft_printf(char *str, ...);
char	*ft_strchr(const char *str, int c);
void hexabase(int nbr);
size_t	ft_strlen(const char *str);


#endif
