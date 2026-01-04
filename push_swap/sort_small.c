/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:22:51 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/04 17:24:16 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
}

static void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && y < z && x < z)
		sa(a, 1);
	else if (x > y && y > z)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (x > y && y < z && x > z)
		ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		rra(a, 1);
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int		min_pos;
	int		size;
	t_stack	*cur;

	min_pos = 0;
	size = stack_size(*a);
	cur = *a;
	while (cur)
	{
		if (cur->index == 0)
			break ;
		min_pos++;
		cur = cur->next;
	}
	if (min_pos <= size / 2)
		while ((*a)->index != 0)
			ra(a, 1);
	else
		while ((*a)->index != 0)
			rra(a, 1);
	pb(a, b, 1);
}

static void	push_next_min_to_b(t_stack **a, t_stack **b)
{
	int		pos;
	int		size;
	t_stack	*cur;

	pos = 0;
	size = stack_size(*a);
	cur = *a;
	while (cur)
	{
		if (cur->index == 1)
			break ;
		pos++;
		cur = cur->next;
	}
	if (pos <= size / 2)
		while ((*a)->index != 1)
			ra(a, 1);
	else
		while ((*a)->index != 1)
			rra(a, 1);
	pb(a, b, 1);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		return (sort_two(a));
	if (size == 3)
		return (sort_three(a));
	if (size == 4)
	{
		push_min_to_b(a, b);
		sort_three(a);
		return (pa(a, b, 1));
	}
	if (size == 5)
	{
		push_min_to_b(a, b);
		push_next_min_to_b(a, b);
		sort_three(a);
		pa(a, b, 1);
		return (pa(a, b, 1));
	}
}