/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:27:54 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/04 17:28:36 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_stack **s)
{
	t_stack	*first;
	t_stack	*tail;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = (*s)->next;
	first->next = NULL;
	tail = *s;
	while (tail->next)
		tail = tail->next;
	tail->next = first;
}

void	ra(t_stack **a, int print)
{
	rotate_up(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	rotate_up(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	rotate_up(a);
	rotate_up(b);
	if (print)
		write(1, "rr\n", 3);
}
