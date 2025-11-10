/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:38:00 by mbahri            #+#    #+#             */
/*   Updated: 2025/08/07 15:26:11 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*p;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	p = malloc(sizeof(int) * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
