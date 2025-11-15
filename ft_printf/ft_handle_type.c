/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:42:32 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/15 11:34:00 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(va_list args)
{
	char	c;
	ssize_t	res;

	c = va_arg(args, int);
	res = write(1, &c, 1);
	return (res);
}

int	ft_putstr_count(va_list args)
{
	char	*str;
	size_t	len;
	ssize_t	res;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	res = write(1, str, len);
	return (res);
}
