/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:42:34 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/30 18:42:34 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = malloc(len + 1);
	if (!sub)
	{
		free(s);
		return (NULL);
	}
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
	if (!line)
		return (NULL);
	ft_strlcpy(line, *tmp, i + 2);
	*tmp = ft_substr(*tmp, i + 1, ft_strlen(*tmp) - i - 1);
	return (line);
}

static char	*ft_join_buff(char *tmp, char *buff)
{
	char	*result;

	if (!tmp)
	{
		result = ft_strdup(buff);
		free(buff);
	}
	else
		result = ft_strjoin(tmp, buff);
	return (result);
}

static int	read_until_newline(int fd, char **tmp)
{
	char	*buff;
	int		res;

	while (ft_strchr(*tmp, '\n') == -1)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
		{
			free(buff);
			break ;
		}
		buff[res] = '\0';
		*tmp = ft_strjoin(*tmp, buff);
		if (!*tmp)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
	tmp = ft_join_buff(tmp, buff);
	if (!tmp || !read_until_newline(fd, &tmp))
		return (NULL);
	return (ft_extract_line(&tmp));
}
