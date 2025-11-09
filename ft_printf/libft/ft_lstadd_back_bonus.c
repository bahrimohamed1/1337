/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:00:47 by mbahri            #+#    #+#             */
/*   Updated: 2025/11/01 14:50:46 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		new->next = NULL;
		return ;
	}
	temp = (*lst);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}
