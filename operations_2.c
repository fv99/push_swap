/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:19:34 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/13 16:14:21 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// mode 1 = shift up all elements of stack a by 1, first becomes last
// mode 0 = shift up all elements of stack b by 1, first becomes last
int	ra_rb(t_stack **stack_a, t_stack **stack_b, int mode)
{
	t_stack *temp;

	if (!stack_a || !*stack_a ||  !(*stack_a)->next)
		return(1);
	if (mode == 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		stackadd_back(stack_a, temp);
		ft_printf("ra\n");
	}
	else
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		stackadd_back(stack_b, temp);
		ft_printf("rb\n");
	}
	update_index(*stack_a);
	return (0);
}

// ra and rb at the same time
int	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return(1);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	stackadd_back(stack_a, temp);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	stackadd_back(stack_b, temp);
	ft_printf("rr\n");
	update_index(*stack_a);
	return (0);
}

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

	if (!stack_a || !*stack_a || !(*stack_a)->next )
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
	update_index(*stack_a);
	return (0);
}

// rra and rrb at the same time
int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !*stack_a)
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
	update_index(*stack_a);
	return (0);
}
