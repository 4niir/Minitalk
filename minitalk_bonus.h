/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:52:55 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/11 16:52:57 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_strchr(char *str, int c);
int		ft_atoi(char *str);
int		ft_printf(const char *s, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(long nb, int *len);
void	ft_puthex(unsigned long nbr, int *len, char format);
void	ft_putptr(unsigned long ptr, int *len);

#endif
