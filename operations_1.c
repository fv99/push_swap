/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:33:07 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/03/30 13:51:11 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa_sb(t_list **stack, int mode)
{
	t_list	*temp;

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
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

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
	return (0);
}

int	pa_pb(t_list **stack_a, t_list **stack_b, int mode)
{
	t_list	*temp;

	if (!stack_a || !stack_b || !*stack_b || !*stack_a)
		return(1);	
	if (mode == 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		ft_lstadd_front(stack_a, temp);
		return(ft_printf("pa\n"));
	}
	else
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		ft_lstadd_front(stack_b, temp);
		return(ft_printf("pb\n"));
	}
}