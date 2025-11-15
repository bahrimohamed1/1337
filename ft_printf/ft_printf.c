/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:40:41 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/15 12:03:55 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char format, va_list args)
{
	if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
		return (ft_putchar_count(args));
	else if (format == 's')
		return (ft_putstr_count(args));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_count(args));
	else if (format == 'u')
		return (ft_putnbr_unsigned_count(args));
	else if (format == 'x')
		return (ft_puthex_count(args, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_puthex_count(args, "0123456789ABCDEF"));
	else if (format == 'p')
		return (ft_handleptr_count(args));
	else
		return (write(1, "%", 1));
}

static int	ft_process_format(const char *format, int *i, va_list args)
{
	int	count;

	if (format[*i] == '%')
	{
		(*i)++;
		if (!format[*i])
			count = write(1, "%", 1);
		else
			count = ft_handle_format(format[*i], args);
	}
	else
		count = write(1, &format[*i], 1);
	(*i)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		temp_count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		temp_count = ft_process_format(format, &i, args);
		if (temp_count == -1)
		{
			va_end(args);
			return (-1);
		}
		count += temp_count;
	}
	va_end(args);
	return (count);
}
