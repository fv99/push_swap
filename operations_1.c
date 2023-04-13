/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:33:07 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/13 16:10:34 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first 2 elements at the top of stack
int	sa_sb(t_stack **stack, int mode)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return(1);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (mode == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	update_index(*stack);
	return (0);
}

// sa and sb at the same time
int	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next \
		|| !stack_b || !*stack_b || !(*stack_b)->next)
		return(1);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	ft_printf("ss\n");
	update_index(*stack_a);
	return (0);
}

// mode 1 = first element at the top of b and put it at the top of a
// mode 0 = first element at the top of a and put it at the top of b.
int	pa_pb(t_stack **stack_a, t_stack **stack_b, int mode)
{
	t_stack	*temp;

	if (!stack_a || !*stack_a || (mode == 1 && (!stack_b || !*stack_b)))
		return(1);	
	if (mode == 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		stackadd_front(stack_a, temp);
		ft_printf("pa\n");
	}
	else
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		stackadd_front(stack_b, temp);
		ft_printf("pb\n");
	}
	update_index(*stack_a);
	return(0);
}
