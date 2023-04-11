/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:48:10 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/11 12:03:28 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

// structs go here
typedef	struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

// push_swap.c

int		you_fucked_up(char *msg);

void	initialize_list(t_stack **lst, int argc, char **argv);

// list_utils_1.c

t_stack	*new_stack(int val);

t_stack	*stack_last(t_stack *stack);

void	stackadd_back(t_stack **stack, t_stack *new);

void	stackadd_front(t_stack **lst, t_stack *new);

void	update_index(t_stack *stack);

// list_utils_2.c

int		stack_size(t_stack *stack);

int		is_sorted(t_stack *stack);

void	free_split(char **str);

void	free_stack(t_stack **stack);

// operations_1.c

int		sa_sb(t_stack **stack, int mode);

int		ss(t_stack **stack_a, t_stack **stack_b);

int		pa_pb(t_stack **stack_a, t_stack **stack_b, int mode);

// operations_2.c

int		ra_rb(t_stack **stack_a, t_stack **stack_b, int mode);

int		rr(t_stack **stack_a, t_stack **stack_b);

t_stack	*find_pre_last(t_stack *stack);

int		rra_rrb(t_stack **stack_a, t_stack **stack_b, int mode);

int		rrr(t_stack **stack_a, t_stack **stack_b);

// sort_3_5.c

int		sort_three(t_stack **stack_a, t_stack **stack_b);

int		sort_five(t_stack **stack_a, t_stack **stack_b);

// test_functions.c

void	test_stack_read(t_stack **a);

int		test_sa_sb(t_stack **stack);

int		test_ss(t_stack **stack_a, t_stack **stack_b);

int		test_pa_pb(t_stack **stack_a, t_stack **stack_b);

int		test_rra_rrb(t_stack **stack_a, t_stack **stack_b);

int		test_rrr(t_stack **stack_a, t_stack **stack_b);

int		test_my_shit(t_stack **stack_a, t_stack **stack_b);