/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:03:11 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/10 16:03:25 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_help(char *str, int len, unsigned int n)
{
	str[len] = '\0';
	while (n >= 10)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[len - 1] = n + '0';
	return (str);
}

static void	ft_len(unsigned int n, int *len)
{
	if (n == 0)
		*len = 1;
	while (n > 0)
	{
		n /= 10;
		(*len)++;
	}
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	ft_len(n, &len);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_help(str, len, n));
}
