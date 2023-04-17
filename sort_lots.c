/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:28:35 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 18:03:17 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gets max bits to represent an index 
int	get_index_bits(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		max_bits;

	temp = *stack;
	max = temp->index;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/*
*   least significant bit (binary) radix sort
*
*   start from least significant bit
*   bitwise shift index value i positions
*   check if least significant bit is 0 or 1
*   distributes between 2 stacks according to least sig bit
*
*   Example: Decimal values: 9, 3, 1, 6
*            Binary values: 1001, 0011, 0001, 0110
*
*   1. Sort by least significant bit (rightmost bit):
*      - Elements with LSB = 0: [0110] (6 in decimal)
*      - Elements with LSB = 1: [1001, 0011, 0001] (9, 3, 1 in decimal)
*      - Combined stacks: [6, 9, 3, 1]
*
*   2. Sort by the second bit from the right:
*      - Elements with LSB = 0: [0110, 0001] (6, 1 in decimal)
*      - Elements with LSB = 1: [1001, 0011] (9, 3 in decimal)
*      - Combined stacks: [6, 1, 9, 3]
*
*   3. Sort by the third bit from the right:
*      - Elements with LSB = 0: [0110, 0011, 0001] (6, 3, 1 in decimal)
*      - Elements with LSB = 1: [1001] (9 in decimal)
*      - Combined stacks: [6, 3, 1, 9]
*
*   4. Sort by the most significant bit (leftmost bit):
*      - Elements with LSB = 0: [0110, 0011, 0001] (6, 3, 1 in decimal)
*      - Elements with LSB = 1: [1001] (9 in decimal)
*      - Combined stacks: [1, 3, 6, 9]
*
*   After processing all bit positions, the numbers are sorted.
 */
int	sort_lots(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	temp = *stack_a;
	size = stack_size(*stack_a);
	max_bits = get_index_bits(stack_a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			temp = *stack_a;
			if (((temp->index >> i) & 1) == 0)
				pa_pb(stack_a, stack_b, 0);
			else
				ra_rb(stack_a, stack_b, 1);
		}
		while (stack_size(*stack_b) != 0)
			pa_pb(stack_a, stack_b, 1);
	}
	return (is_sorted(*stack_a));
}
