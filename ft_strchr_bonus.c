/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:58:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/11 17:16:13 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *) str;
	i = 0;
	while (ptr[i] != (char)c)
	{
		if (!ptr[i])
			return (NULL);
		i++;
	}
	return (ptr + i);
}
