/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbahri <mbahri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:25:41 by mbahri            #+#    #+#             */
/*   Updated: 2026/01/03 14:19:00 by mbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		parse_arguments(int argc, char **argv, t_stack **stack_a);
int		parse_string_arg(char *arg, t_stack **stack_a);
int		is_valid_int(char *str, long *num);
int		has_duplicates(t_stack *stack);
void	error_exit(t_stack **stack_a);
void	assign_indexes(t_stack *stack_a);
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
char	**ft_split(char const *s, char c);

#endif