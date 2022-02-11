/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:20:03 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/10 20:31:57 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

void	ft_formats(va_list args, const char format, int *len, char data)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putnbr(va_arg(args, unsigned int), len);
	else if (format == 'x' || format == 'X')
		ft_puthex (va_arg(args, unsigned int), len, format);
	else if (format == 'p')
		ft_putptr(va_arg(args, unsigned long), len);
	else if (format == '%')
		ft_putchar('%', len);
	else
		ft_putchar(data, len);
}

int	ft_printf(const char *data, ...)
{
	int		len;
	int		position;	
	va_list	args;

	position = 0;
	len = 0;
	va_start(args, data);
	while (data[position])
	{
		if (data[position] != '%')
			ft_putchar(data[position], &len);
		else
		{
			position++;
			while (data[position] == ' ')
				position++;
			if (data[position] == 0)
				break ;
			ft_formats(args, data[position], &len, data[position]);
		}
		position++;
	}
	va_end(args);
	return (len);
}
