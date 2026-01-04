/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:10:07 by mbahri            #+#    #+#             */
/*   Updated: 2025/12/30 03:46:08 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str, long *num)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long)INT_MAX + 1))
			return (0);
		str++;
	}
	*num = result * sign;
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	long	num;
	t_stack	*new_node;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i], &num))
			return (0);
		new_node = stack_new((int)num);
		if (!new_node)
		{
			free_stack(stack_a);
			return (0);
		}
		stack_add_back(stack_a, new_node);
		i++;
	}
	if (has_duplicates(*stack_a))
		return (0);
	return (1);
}

void	error_exit(t_stack **stack_a)
{
	if (stack_a)
		free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	assign_indexes(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack_a;
	while (current)
	{
		index = 0;
		compare = stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
