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

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_get_line(char *stash)
{
	char	*line;
	int		len;

	len = 0;
	if (!stash[len])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	line = ft_substr(stash, 0, len + (stash[len] == '\n'));
	return (line);
}

static char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	int		len;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, len + 1, ft_strlen(stash) - len - 1);
	free(stash);
	return (new_stash);
}

static char	*ft_read_file(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free(&stash));
	bytes = 1;
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			return (ft_free(&stash));
		}
		buff[bytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_update_stash(stash[fd]);
	return (line);
}
