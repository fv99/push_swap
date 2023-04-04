/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:19:34 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/04 15:41:38 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds second to last element of stack
t_stack	*find_pre_last(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

// mode 1 = shift down all elements of stack a by 1, last becomes first
// mode 0 = shift down all elements of stack b by 1, last becomes first
int	rra_rrb(t_stack **stack_a, t_stack **stack_b, int mode)
{
	t_stack *temp;

	if (!stack_a || !stack_b || !*stack_b || !*stack_a ||\
		!(*stack_a)->next || !(*stack_b)->next)
		return(1);
	if (mode == 1)
	{
		temp = stack_last(*stack_a);
		find_pre_last(*stack_a)->next = NULL;
		stackadd_front(stack_a, temp);
		temp = stack_last(*stack_a);
		temp->next = NULL;
		ft_printf("rra\n");
	}
	else
	{
		temp = stack_last(*stack_b);
		find_pre_last(*stack_b)->next = NULL;
		stackadd_front(stack_b, temp);
		temp = stack_last(*stack_b);
		temp->next = NULL;
		ft_printf("rrb\n");
	}
	return (0);
}

// rra and rrb at the same time
int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !stack_b || !*stack_b || !*stack_a ||\
		!(*stack_a)->next || !(*stack_b)->next)
		return(1);
	temp = stack_last(*stack_a);
	find_pre_last(*stack_a)->next = NULL;
	stackadd_front(stack_a, temp);
	temp = stack_last(*stack_a);
	temp->next = NULL;
	temp = stack_last(*stack_b);
	find_pre_last(*stack_b)->next = NULL;
	stackadd_front(stack_b, temp);
	temp = stack_last(*stack_b);
	temp->next = NULL;
	ft_printf("rrr\n");
	return (0);
}

