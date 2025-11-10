/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:02:24 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/10 16:05:02 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_decimal(va_list args)
{
	int		num;
	char	*str;
	int		count;

	num = va_arg(args, int);
	str = ft_itoa(num);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_handle_unsigned(va_list args)
{
	unsigned int	num;
	char			*str;
	int				count;

	num = va_arg(args, unsigned int);
	str = ft_utoa(num);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_handle_hex(va_list args)
{
	unsigned int	num;
	char			*str;
	int				count;

	num = va_arg(args, unsigned int);
	str = ft_utoa_base(num, "0123456789abcdef");
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_handle_upper_hex(va_list args)
{
	unsigned int	num;
	char			*str;
	int				count;

	num = va_arg(args, unsigned int);
	str = ft_utoa_base(num, "0123456789ABCDEF");
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_handle_pointer(va_list args)
{
	unsigned long	num;
	char			*str;
	int				count;

	num = va_arg(args, unsigned long);
	if (num == 0)
		return (ft_putstr("(null)"));
	count = ft_putstr("0x");
	str = ft_utoa_base(num, "0123456789abcdef");
	count += ft_putstr(str);
	free(str);
	return (count);
}
