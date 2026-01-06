/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:10:46 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/06 17:58:46 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index_pos(t_stack *b, int *pos)
{
	int	max;
	int	i;

	if (!b)
		return (0);
	max = b->index;
	i = 0;
	*pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			*pos = i;
		}
		b = b->next;
		i++;
	}
	return (max);
}

static void	push_back_max(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;
	int	max;

	while (*b)
	{
		size = stack_size(*b);
		max = get_max_index_pos(*b, &pos);
		if (pos <= size / 2)
			while ((*b)->index != max)
				rb(b, 1);
		else
			while ((*b)->index != max)
				rrb(b, 1);
		pa(a, b, 1);
	}
}

static void	push_chunk(t_stack **a, t_stack **b, int start, int chunk)
{
	while (*a)
	{
		if ((*a)->index <= start)
		{
			pb(a, b, 1);
			rb(b, 1);
			start++;
		}
		else if ((*a)->index <= chunk + start)
		{
			pb(a, b, 1);
			start++;
		}
		else
			ra(a, 1);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk;
	int	start;

	size = stack_size(*a);
	if (size <= 100)
		chunk = 15;
	else if (size <= 500)
		chunk = 35;
	start = 0;
	push_chunk(a, b, start, chunk);
	push_back_max(a, b);
}
