/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:39:54 by mbahri            #+#    #+#             */
/*   Updated: 2025/08/07 15:28:30 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*p;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	p = malloc(sizeof(int) * size);
	if (!p)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		p[i] = min + i;
		i++;
	}
	*range = p;
	return (size);
}
