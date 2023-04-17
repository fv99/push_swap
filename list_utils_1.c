/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:37:13 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 18:05:35 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// list functions
t_stack	*new_stack(int val)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = val;
	stack->index = -1;
	stack->next = NULL;
	return (stack);
}

// returns last element of stack
t_stack	*stack_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = stack_last(*stack);
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

void	stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

// updates index according to min value
void	update_index(t_stack *stack)
{
	t_stack	*temp;
	int		index;

	temp = stack;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	index = 0;
	temp = get_min(&stack);
	while (temp)
	{
		temp->index = index++;
		temp = get_min(&stack);
	}
}
