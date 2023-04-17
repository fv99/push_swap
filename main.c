/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:34:23 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 17:34:48 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        you_fucked_up("Invalid number of arguments");
    else
    {
		check_input(argv);
		stack_a = NULL;
		stack_b = NULL;
        initialize_list(&stack_a, argc, argv);
		// test_stack_read(&stack_a);
        // test_stack_read(&stack_b);
        push_swap(&stack_a, &stack_b, argc);
        // test_stack_read(&stack_a);
        // test_stack_read(&stack_b);
        // test_my_shit(a, b);
        free_stack(&stack_a);
        free_stack(&stack_b);
    }
    return (0);
}