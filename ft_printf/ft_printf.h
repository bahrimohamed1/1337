/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:29:46 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/15 13:33:56 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_count(va_list args);
int		ft_putstr_count(va_list args);
int		ft_putnbr_count(va_list args);
int		ft_putnbr_unsigned_count(va_list args);
int		ft_puthex_count(va_list args, char *s);
int		ft_handleptr_count(va_list args);
char	*ft_utoa(unsigned int n);
char	*ft_ultoa_hex(unsigned long n, char *base);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);

#endif
