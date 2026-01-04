/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 01:03:42 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/03 16:20:37 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_input(int argc, char **argv, t_stack **a)
{
	if (argc == 2)
	{
		if (!parse_string_arg(argv[1], a))
			error_exit(a);
	}
	else if (!parse_arguments(argc, argv, a))
		error_exit(a);
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
	if (is_sorted(a))
		return (free_stack(&a), 0);
	assign_indexes(a);
	if (stack_size(a) <= 5)
		sort_small(&a, &b);
	else
		radix_sort(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
