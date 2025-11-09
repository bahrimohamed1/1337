/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:05:30 by mbahri            #+#    #+#             */
/*   Updated: 2025/10/29 12:41:19 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = s1;
	ptr2 = s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && ptr1[i] == ptr2[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
