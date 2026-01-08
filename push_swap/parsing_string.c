/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:19:35 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/06 22:44:34 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	parse_tokens(char **tokens, t_stack **stack_a)
{
	int		i;
	long	num;
	t_stack	*node;

	i = 0;
	while (tokens[i])
	{
		if (!is_valid_int(tokens[i], &num))
			return (0);
		node = stack_new((int)num);
		if (!node)
			return (0);
		stack_add_back(stack_a, node);
		i++;
	}
	if (i == 0 || has_duplicates(*stack_a))
		return (0);
	return (1);
}

int	parse_string_arg(char *arg, t_stack **stack_a)
{
	char	**tokens;
	int		ok;

	if (!arg || !*arg)
		return (0);
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	ok = parse_tokens(tokens, stack_a);
	free_tokens(tokens);
	return (ok);
}

void	parse_input(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_string_arg(argv[i], a))
			error_exit(a);
		i++;
	}
}
