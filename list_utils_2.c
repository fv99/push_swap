/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:20:37 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/16 17:39:51 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns size of stack passed as parameter
int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

// checks if list is sorted, 1 if yes 0 if no
int	is_sorted(t_stack *stack)
{
	if (!stack)
		you_fucked_up("is_sorted failed");
	while(stack)
	{
		if (!stack->next)
			return(1);
		if (stack->num > stack->next->num)
			return(0);
		stack = stack->next;
	}
	return (1);
}

// will free array of strings created by ft_split
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// frees stack
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack || !*stack)
		return;
	tmp = *stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
	// free(stack);
}

// gets min value for index
t_stack	*get_min(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		min;

	if (!(*stack))
		return (NULL);
	min = INT_MAX;
	min_node = NULL;
	temp = *stack;
	while (temp)
	{
		if (temp->index == -1 && temp->num < min)
		{
			min = temp->num;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}
