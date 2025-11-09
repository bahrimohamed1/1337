/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:06:27 by mbahri            #+#    #+#             */
/*   Updated: 2025/10/29 08:56:13 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_help(char *str, int len, int n, int sign)
{
	str[len] = '\0';
	while (n >= 10)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[len - 1] = n + '0';
	if (sign == 1)
		str[0] = '-';
	return (str);
}

static void	ft_len(int n, int *len)
{
	if (n == 0)
		*len = 1;
	while (n > 0)
	{
		n /= 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
		sign = 1;
	}
	ft_len(n, &len);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_help(str, len, n, sign));
}
