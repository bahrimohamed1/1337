/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:17:45 by mbahri            #+#    #+#             */
/*   Updated: 2025/10/19 16:18:09 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	j = 0;
	while (big[j] && j < len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while (big[j + i] == little[i] && j + i < len && little[i])
				i++;
			if (!little[i])
				return ((char *)&big[j]);
		}
		j++;
	}
	return (0);
}
