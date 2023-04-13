/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:31:47 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/13 16:00:31 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*temp;

	temp = *stack_a;
	if (stack_size(*stack_a) == 2 && temp->num > temp->next->num)
			sa_sb(stack_a, 1);
	if (temp->num > temp->next->num && temp->next->num < temp->next->next->num && temp->num < temp->next->next->num)
		sa_sb(stack_a, 1);
	else if (temp->num > temp->next->num && temp->next->num > temp->next->next->num)
	{
		sa_sb(stack_a, 1);
		rra_rrb(stack_a, stack_b, 1);
	}
	else if (temp->num > temp->next->num && temp->next->num < temp->next->next->num && temp->num > temp->next->next->num)
		ra_rb(stack_a, stack_b, 1);
	else if (temp->num < temp->next->num && temp->next->num > temp->next->next->num && temp->num < temp->next->next->num)
	{
		sa_sb(stack_a, 1);
		ra_rb(stack_a, stack_b, 1);
	}
	else if (temp->num < temp->next->num && temp->next->num > temp->next->next->num && temp->num > temp->next->next->num)
		rra_rrb(stack_a, stack_b, 1);
	return (is_sorted(*stack_a));
}

int	rotate_sort_5(t_stack **stack_a, t_stack **stack_b, t_stack *val, int sel)
{
	int index;

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

int	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		pa_pb(stack_a, stack_b, 0);
		pa_pb(stack_a, stack_b, 0);
		sort_three(stack_a, stack_b);
		while (stack_b)
			pa_pb(stack_a, stack_b, 1);
		rotate_sort_5(stack_a, stack_b, *stack_a, 0);
	}
	return (is_sorted(*stack_a));
}