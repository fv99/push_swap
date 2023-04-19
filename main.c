/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:34:23 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/19 16:39:27 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	else
	{
		check_input(argv);
		stack_a = NULL;
		stack_b = NULL;
		initialize_list(&stack_a, argc, argv);
		if (!is_sorted(stack_a))
			push_swap(&stack_a, &stack_b, argc);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
