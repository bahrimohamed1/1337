/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:08:28 by mbahri            #+#    #+#             */
/*   Updated: 2025/08/07 15:46:09 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_total(int size, char **strs, char *sep)
{
	int	sep_len;
	int	total;
	int	i;

	sep_len = ft_strlen(sep);
	total = 0;
	i = 0;
	while (i < size)
	{
		total = total + ft_strlen(strs[i]);
		i++;
	}
	total += sep_len * (size - 1);
	return (total);
}

int	ft_copy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*join_piece(char *p, char *s, char *sep, int add_sep)
{
	int	n;

	n = ft_copy(p, s);
	p += n;
	if (add_sep)
	{
		n = ft_copy(p, sep);
		p += n;
	}
	return (p);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*p;
	int		i;
	int		add_sep;

	if (size <= 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = malloc(ft_total(size, strs, sep) + 1);
	if (!res)
		return (NULL);
	p = res;
	i = 0;
	while (i < size)
	{
		add_sep = (i + 1 < size);
		p = join_piece(p, strs[i], sep, add_sep);
		i++;
	}
	p[0] = '\0';
	return (res);
}
