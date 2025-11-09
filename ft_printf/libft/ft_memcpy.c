/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:34:31 by mbahri            #+#    #+#             */
/*   Updated: 2025/10/16 22:53:52 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*buffer;
	const unsigned char	*temp;

	temp = src;
	buffer = dest;
	i = 0;
	while (i < n)
	{
		buffer[i] = temp[i];
		i++;
	}
	return (dest);
}
