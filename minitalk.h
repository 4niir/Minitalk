/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:59:39 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/09 13:45:57 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stddef.h>

char	*ft_strchr(char *str, int c);
int		ft_atoi(char *str);
int		ft_printf(const char *s, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(long nb, int *len);
void	ft_puthex(unsigned long nbr, int *len, char format);
void	ft_putptr(unsigned long ptr, int *len);

#endif
