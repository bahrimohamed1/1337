/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:13:30 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/26 23:33:37 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_helper(char *ptr, char **buffer)
{
	int		n;
	char	*str;
	int		i;
	char	*temp;
	
	temp = *buffer;
	n = ft_strchr(ptr, '\n');
	str = malloc(n + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (i <= n)
		str[i] = ptr[i++];
	str[i] = '\0';
	i = 0;
	while (temp[i])
	{
		temp[i] = ptr[++n];
		i++;
	}
	temp[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ptr;
	char		*str;
	int			res;

	ptr = buffer;
	while (ft_strchr(ptr, '\n') == -1)
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		res = read(fd, str, BUFFER_SIZE);
		if (res > 0)
			str[res] = '\0';
		ptr = ft_strjoin(ptr, str);
	}
	if (ptr)
		ft_helper(ptr, &buffer);
}
