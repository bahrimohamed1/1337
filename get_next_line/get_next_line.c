/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:36:39 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/22 16:36:39 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	free(s);
	return (sub);
}

char	*get_next_line(int  fd)
{
	char		*buff;
	static char	*tmp;
	int			res;
	int			i;
	char		*line;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	res = read(fd, buff, BUFFER_SIZE);
	buff[res] = '\0';
	tmp = ft_strdup(buff);
	if (!tmp)
		return (NULL);
	free(buff);
	while (!ft_strchr(tmp, '\n'))
	{
		buff = malloc(BUFFER_SIZE + 1);
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
		{
			free(buff);
			break;
		}
		buff[res] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
		{
			free(buff);
			break;
		}
	}
	i = ft_strchr(tmp, '\n');
	if (i == -1)
	{
		line = ft_strdup(tmp);
		free(tmp);
		return (line);
	}
	line = malloc(i + 1);
	ft_strlcpy(line, tmp, i + 1);
	tmp = ft_substr(tmp, i, ft_strlen(tmp) - i);
	return (line);
}
