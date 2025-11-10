/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:02:33 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/10 16:05:43 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_len(unsigned long n, int *len, int base_len)
{
	if (n == 0)
		*len = 1;
	while (n > 0)
	{
		n /= base_len;
		(*len)++;
	}
}

static char	*ft_help(char *str, int len, unsigned long n, char *base_charset)
{
	size_t	base_len;

	base_len = ft_strlen(base_charset);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = base_charset[0];
		return (str);
	}
	while (n > 0)
	{
		len--;
		str[len] = base_charset[n % base_len];
		n /= base_len;
	}
	return (str);
}

char	*ft_utoa_base(unsigned long n, char *base_charset)
{
	int		len;
	size_t	base_len;
	char	*str;

	if (!base_charset)
		return (NULL);
	base_len = ft_strlen(base_charset);
	len = 0;
	ft_len(n, &len, base_len);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_help(str, len, n, base_charset));
}
