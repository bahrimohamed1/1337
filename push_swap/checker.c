/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:13:19 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/06 22:13:22 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fail(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	exec_op(char *op, t_stack **a, t_stack **b)
{
	if (!op)
		return (0);
	if (!ft_strncmp(op, "sa\n", 3) || !ft_strncmp(op, "sa", 3))
		return (sa(a, 0), 1);
	if (!ft_strncmp(op, "sb\n", 3) || !ft_strncmp(op, "sb", 3))
		return (sb(b, 0), 1);
	if (!ft_strncmp(op, "ss\n", 3) || !ft_strncmp(op, "ss", 3))
		return (ss(a, b, 0), 1);
	if (!ft_strncmp(op, "pa\n", 3) || !ft_strncmp(op, "pa", 3))
		return (pa(a, b, 0), 1);
	if (!ft_strncmp(op, "pb\n", 3) || !ft_strncmp(op, "pb", 3))
		return (pb(a, b, 0), 1);
	if (!ft_strncmp(op, "ra\n", 3) || !ft_strncmp(op, "ra", 3))
		return (ra(a, 0), 1);
	if (!ft_strncmp(op, "rb\n", 3) || !ft_strncmp(op, "rb", 3))
		return (rb(b, 0), 1);
	if (!ft_strncmp(op, "rr\n", 3) || !ft_strncmp(op, "rr", 3))
		return (rr(a, b, 0), 1);
	if (!ft_strncmp(op, "rra\n", 4) || !ft_strncmp(op, "rra", 4))
		return (rra(a, 0), 1);
	if (!ft_strncmp(op, "rrb\n", 4) || !ft_strncmp(op, "rrb", 4))
		return (rrb(b, 0), 1);
	if (!ft_strncmp(op, "rrr\n", 4) || !ft_strncmp(op, "rrr", 4))
		return (rrr(a, b, 0), 1);
	return (0);
}

static void	run_checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_op(line, a, b))
		{
			free(line);
			fail(a, b);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && stack_size(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	parse_input(argc, argv, &a);
	run_checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
