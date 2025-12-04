/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:07:10 by mbahri            #+#    #+#             */
/*   Updated: 2025/12/03 14:07:10 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_check(char *tmp, char *buffer)
{
	char	*result;

	if (!tmp)
		result = ft_strdup(buffer);
	else
	{
		result = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (result);
}

char	*ft_get_line(char **tmp)
{
	char	*keep_tmp;
	char	*line;
	int		i;
	size_t	len;

	if (!*tmp)
		return (NULL);
	i = ft_strchr(*tmp, '\n');
	line = ft_substr(*tmp, 0, i + 1);
	len = ft_strlen(*tmp);
	keep_tmp = ft_substr(*tmp, i + 1, len - (i + 1));
	if (!keep_tmp)
		return (NULL);
	free(*tmp);
	*tmp = keep_tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buffer;
	char		*line;
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tmp && ft_strchr(tmp, '\n') >= 0)
			return (ft_get_line(&tmp));
	res = 1;
	while (res > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (res == 0)
		{
			free(buffer)
			break;
		}
		buffer[res] = '\0';
		tmp = ft_check(tmp, buffer);
		if (!tmp)
			return (NULL);
	}
	return (ft_get_line(&tmp));
}
