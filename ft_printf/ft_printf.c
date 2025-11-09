/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:27:45 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/09 21:53:51 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
static int	ft_putstr(char *s)
{
	int	count;
	int	i;

	if (!s)
		s = "(null)";
	while (s[i])
	{
		count++;
		write(1, s[i], 1);
		i++;
	}
	return (count);
}

static int	ft_handle_format(char specifier, va_list args)
{
	char	c;
	char	*str;

	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'c')
	{
		c = (char)va_arg(args, int);
		return (ft_putchar(c));
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		return (ft_putstr(str));
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int		i;
		char	*str;
		int		count;

		i = va_arg(args, int);
		str = ft_itoa(i);
		count = ft_putstr(str);
		free(str);
		return (count);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
