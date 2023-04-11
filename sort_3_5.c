/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:31:47 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/11 16:05:31 by fvonsovs         ###   ########.fr       */
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

int find_min_index(t_stack *stack, int start_index)
{
    t_stack *temp;
    int min_index;
    int min_value;

    temp = stack;
    // Move the pointer to the starting index
    while (temp && temp->index < start_index)
    {
        temp = temp->next;
    }

    // Initialize min_value and min_index
    if (temp)
    {
        min_value = temp->num;
        min_index = temp->index;
    }
    else
    {
        return -1;
    }

    // Find the index of the smallest element
    while (temp)
    {
        if (temp->num < min_value)
        {
            min_value = temp->num;
            min_index = temp->index;
        }
        temp = temp->next;
    }

    return min_index;
}


int	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min_index_1;
	int		min_index_2;

	if (!is_sorted(*stack_a))
	{
		min_index_1 = find_min_index(*stack_a, 0);
		min_index_2 = find_min_index(*stack_a, min_index_1 + 1);

		pa_pb(stack_a, stack_b, 0);
		pa_pb(stack_a, stack_b, 0);
		sort_three(stack_a, stack_b);
		pa_pb(stack_a, stack_b, 1);
		pa_pb(stack_a, stack_b, 1);
	}
	return (is_sorted(*stack_a));
}