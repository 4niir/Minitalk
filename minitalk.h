
#ifndef MINITALK_H
#define MINITALK_H

# include<stdlib.h>
# include<stdlib.h>
# include<stdarg.h>
# include<unistd.h>


char 	*ft_strchr(char *str, int c);
int 	ft_atoi(char *str);
int 	ft_strlen(char *str);
int 	ft_printf(const char *s, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(long nb, int *len);
void	ft_puthex(unsigned long nbr, int *len, char format);
void	ft_putptr(unsigned long ptr, int *len);

# endif