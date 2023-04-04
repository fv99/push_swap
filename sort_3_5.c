/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:31:47 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/04 17:40:24 by fvonsovs         ###   ########.fr       */
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
int	sort_three(t_stack **stack_a)
{
	t_stack	*temp;

	while (!is_sorted(*stack_a))
	{
		temp = *stack_a;
		if (stack_size(*stack_a) == 2)
			sa_sb(stack_a, 1);
		else if ((temp->num) < (temp->next->num)
			&& (temp->num) > (temp->next->next->num))
			rra_rrb(stack_a, NULL, 1);
		else if ((temp->num) > (temp->next->num)
			&& (temp->num) > (temp->next->next->num))
			ra_rb(stack_a, NULL, 1);
		else
			sa_sb(stack_a, 1);
	}
	return (is_sorted(*stack_a));
}