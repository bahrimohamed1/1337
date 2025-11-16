/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:11:17 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/16 11:00:04 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa_hex(unsigned long n, char *base)
{
	unsigned long	temp;
	int				len;
	char			*str;

	temp = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (temp > 0)
	{
		len++;
		temp /= 16;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = base[n % 16];
		n /= 16;
	}
	return (str);
}
