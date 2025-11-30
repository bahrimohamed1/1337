/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:43:33 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/30 18:43:33 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!line)
		return (NULL);
	ft_strlcpy(line, *tmp, i + 2);
	*tmp = ft_substr(*tmp, i + 1, ft_strlen(*tmp) - i - 1);
	return (line);
}

static void	read_until_newline(int fd, char **tmp)
{
	char	*buff;
	int		res;

	while (*tmp && ft_strchr(*tmp, '\n') == -1)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (! buff)
			return ;
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
		{
			free(buff);
			return ;
		}
		buff[res] = '\0';
		*tmp = ft_strjoin(*tmp, buff);
	}
}

static int	ft_read_and_join(int fd, char **tmp)
{
	char	*buff;
	int		res;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	res = read(fd, buff, BUFFER_SIZE);
	if (res <= 0)
	{
		free(buff);
		return (0);
	}
	buff[res] = '\0';
	if (!*tmp)
		*tmp = ft_strdup(buff);
	else
		*tmp = ft_strjoin(*tmp, buff);
	free(buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffers[1024];
	char		**tmp;

	tmp = &buffers[fd];
	if (*tmp && ft_strchr(*tmp, '\n') != -1)
		return (ft_extract_line(tmp));
	if (! ft_read_and_join(fd, tmp))
	{
		if (*tmp && (*tmp)[0] != '\0')
			return (ft_extract_line(tmp));
		return (NULL);
	}
	if (! *tmp)
		return (NULL);
	read_until_newline(fd, tmp);
	return (ft_extract_line(tmp));
}
