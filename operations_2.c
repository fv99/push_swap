/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:19:34 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/04 15:37:18 by fvonsovs         ###   ########.fr       */
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

// mode 1 = shift up all elements of stack a by 1, first becomes last
// mode 0 = shift up all elements of stack b by 1, first becomes last
int	ra_rb(t_stack **stack_a, t_stack **stack_b, int mode)
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
		ft_printf("ra\n");
	}
	else
	{
		temp = stack_last(*stack_b);
		find_pre_last(*stack_b)->next = NULL;
		stackadd_front(stack_b, temp);
		temp = stack_last(*stack_b);
		temp->next = NULL;
		ft_printf("rb\n");
	}
	return (0);
}

// ra and rb at the same time
int	rr(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf("rr\n");
	return (0);
}