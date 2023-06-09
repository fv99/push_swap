/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:31:47 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 18:00:57 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// norminette bs
int	check_case(t_stack *stack_a, int case_a, int case_b, int case_c)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->num;
	b = stack_a->next->num;
	c = stack_a->next->next->num;
	return (case_a == (a > b) && case_b == (b < c) && case_c == (a < c));
}

/* 
For 3 numbers

Case 1: 2 1 3 > sa > 1 2 3
Case 2: 3 2 1 > sa > 2 3 1 > rra > 1 2 3
Case 3:	3 1 2 > ra > 1 2 3
Case 4:	1 3 2 > sa > 3 1 2 > ra >  1 2 3
Case 5:	2 3 1 > rra > 1 2 3
 */
int	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 2 && !is_sorted(*stack_a))
		sa_sb(stack_a, 1);
	else if (check_case(*stack_a, 1, 1, 1))
		sa_sb(stack_a, 1);
	else if (check_case(*stack_a, 1, 0, 0))
	{
		sa_sb(stack_a, 1);
		rra_rrb(stack_a, stack_b, 1);
	}
	else if (check_case(*stack_a, 1, 1, 0))
		ra_rb(stack_a, stack_b, 1);
	else if (check_case(*stack_a, 0, 0, 1))
	{
		sa_sb(stack_a, 1);
		ra_rb(stack_a, stack_b, 1);
	}
	else if (check_case(*stack_a, 0, 0, 0))
		rra_rrb(stack_a, stack_b, 1);
	return (is_sorted(*stack_a));
}

// rotates depending on position of val to put it at bottom
int	rotate_sort_5(t_stack **stack_a, t_stack **stack_b, t_stack *val, int sel)
{
	int	index;

	if (!stack_a || !*stack_a || !val)
		return (you_fucked_up("error in rotate_sort_5"));
	index = val->index;
	if (index < 0)
		return (you_fucked_up("error in rotate_sort_5"));
	if (index < (stack_size(*stack_a) - index))
	{
		while ((*stack_a)->num != val->num)
			ra_rb(stack_a, stack_b, sel);
	}
	else
	{
		while ((*stack_a)->num != val->num)
			rra_rrb(stack_a, stack_b, sel);
	}	
	return (0);
}

// finds the minimum element in a stack
t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	min = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

/* 
find the minimum element in stack a
rotates stack to place min at top, pb
find second minimum, pb
sorts the three remaining in sort five
pushes all into stack a
 */
int	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	if (!is_sorted(*stack_a))
	{
		min = find_min(*stack_a);
		rotate_sort_5(stack_a, stack_b, min, 1);
		pa_pb(stack_a, stack_b, 0);
		min = find_min(*stack_a);
		rotate_sort_5(stack_a, stack_b, min, 1);
		pa_pb(stack_a, stack_b, 0);
		sort_three(stack_a, stack_b);
		while (*stack_b)
			pa_pb(stack_a, stack_b, 1);
	}
	return (is_sorted(*stack_a));
}
