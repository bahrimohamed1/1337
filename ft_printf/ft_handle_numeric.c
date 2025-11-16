/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:51:28 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/16 10:58:23 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(va_list args)
{
	char	*str;
	size_t	len;
	ssize_t	res;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (-1);
	len = ft_strlen(str);
	res = write(1, str, len);
	free(str);
	return (res);
}

int	ft_putnbr_unsigned_count(va_list args)
{
	char	*str;
	size_t	len;
	ssize_t	res;

	str = ft_utoa(va_arg(args, unsigned int));
	if (!str)
		return (-1);
	len = ft_strlen(str);
	res = write(1, str, len);
	free(str);
	return (res);
}

int	ft_puthex_count(va_list args, char *s)
{
	char	*str;
	size_t	len;
	ssize_t	res;

	str = ft_ultoa_hex(va_arg(args, unsigned int), s);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	res = write(1, str, len);
	free(str);
	return (res);
}

int	ft_handleptr_count(va_list args)
{
	size_t	len;
	ssize_t	res;
	ssize_t	res1;
	char	*str;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	res = write(1, "0x", 2);
	if (res == -1)
		return (res);
	str = ft_ultoa_hex((unsigned long)ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	res1 = write(1, str, len);
	free(str);
	if (res1 == -1)
		return (res1);
	return (res + res1);
}
