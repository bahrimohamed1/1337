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

static char	*ft_substr(char *s, unsigned int start, size_t len)
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

static char	*ft_extract_line(char **tmp)
{
	int		i;
	char	*line;

	i = ft_strchr(*tmp, '\n');
	if (i == -1)
	{
		line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		return (line);
	}
	line = malloc(i + 2);
	ft_strlcpy(line, *tmp, i + 2);
	if (!line)
		return (NULL);
	*tmp = ft_substr(*tmp, i + 1, ft_strlen(*tmp) - i - 1);
	return (line);
}

char	*get_next_line(int  fd)
{
	static char	*tmp;
	char		*buff;
	int			res;

	if (tmp && ft_strchr(tmp, '\n') != -1)
		return (ft_extract_line(&tmp));
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	res = read(fd, buff, BUFFER_SIZE);
	if (res <= 0)
	{
		free(buff);
		if (tmp && tmp[0] != '\0')
			return (ft_extract_line(&tmp));
		return (NULL);
	}
	buff[res] = '\0';
	if (!tmp)
	{
		tmp = ft_strdup(buff);
		free(buff);
	}
	else
		tmp = ft_strjoin(tmp, buff);
	if (!tmp)
		return (NULL);
	while (ft_strchr(tmp, '\n') == -1)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
		{
			free(buff);
			break;
		}
		buff[res] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
			break;
	}
	if (!tmp)
		return (NULL);
	return (ft_extract_line(&tmp));
}
