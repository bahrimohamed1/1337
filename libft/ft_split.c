/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:45:26 by mbahri            #+#    #+#             */
/*   Updated: 2025/10/24 11:21:53 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	sign;

	i = 0;
	sign = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			sign = 1;
		if (s[i] == c && sign == 1)
		{
			count++;
			sign = 0;
		}
		i++;
	}
	if (sign == 1)
		count++;
	return (count);
}

static int	ft_count_len(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static void	*ft_free(char **ptr, int j)
{
	while (j > 0)
	{
		j--;
		free(ptr[j]);
	}
	free(ptr);
	return (0);
}

static char	*ft_handle_word(const char *s, char c, int *i)
{
	int		len;
	char	*word;

	len = ft_count_len(&s[*i], c);
	word = ft_substr(s, *i, len);
	if (!word)
		return (0);
	*i += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	if (!s)
		return (0);
	ptr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ptr[j] = ft_handle_word(s, c, &i);
			if (!ptr[j])
				return (ft_free(ptr, j));
			j++;
		}
	}
	ptr[j] = 0;
	return (ptr);
}
