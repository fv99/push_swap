/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:20:43 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/04 15:41:11 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_stack_read(t_stack **a)
{
    t_stack *buf;

    if (a == NULL || *a == NULL)
    {
        return;
    }
    buf = *a;
    while (buf != NULL)
    {
        ft_printf("%i ", buf->num);
        buf = buf->next;
    }
    ft_printf("\n");
}

int test_sa_sb(t_stack **stack)
{
	ft_printf("\t Test sa_sb:\n");
    ft_printf("Initial stack: ");
    test_stack_read(stack);
    sa_sb(stack, 0);
    ft_printf("After sa stack: ");
    test_stack_read(stack);

    return (0);
}

int test_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\t Test ss:\n");
    ft_printf("Initial stack A: ");
    test_stack_read(stack_a);
    ft_printf("Initial stack B: ");
    test_stack_read(stack_b);
    ss(stack_a, stack_b);
    ft_printf("\nAfter ss stack A: ");
    test_stack_read(stack_a);
    ft_printf("After ss stack B: ");
    test_stack_read(stack_b);
    return (0);
}

int test_pa_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\t Test pa_pb:\n");
    ft_printf("Initial stack A: ");
    test_stack_read(stack_a);
    ft_printf("Initial stack B: ");
    test_stack_read(stack_b);

    pa_pb(stack_a, stack_b, 1);
    pa_pb(stack_a, stack_b, 0);

    ft_printf("\nAfter pa stack A: ");
    test_stack_read(stack_a);
    ft_printf("After pb stack B: ");
    test_stack_read(stack_b);

    return 0;
}

int test_rra_rrb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\t Test rra_rrb:\n");
    ft_printf("Initial stack A: ");
    test_stack_read(stack_a);
    ft_printf("Initial stack B: ");
    test_stack_read(stack_b);

    rra_rrb(stack_a, stack_b, 1);
    rra_rrb(stack_a, stack_b, 0);

    ft_printf("\nAfter rra stack A: ");
    test_stack_read(stack_a);
    ft_printf("After rrb stack B: ");
    test_stack_read(stack_b);

    return 0;
}

int test_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\t Test rrr:\n");
    ft_printf("Initial stack A: ");
    test_stack_read(stack_a);
    ft_printf("Initial stack B: ");
    test_stack_read(stack_b);
    rrr(stack_a, stack_b);
    ft_printf("\nAfter rrr stack A: ");
    test_stack_read(stack_a);
    ft_printf("After rrr stack B: ");
    test_stack_read(stack_b);
    return (0);
}

int test_my_shit(t_stack **a, t_stack **b)
{
		test_stack_read(a);
		test_sa_sb(a);
		test_pa_pb(a, b);
		test_ss(a, b);
		test_rra_rrb(a, b);
		test_rrr(a, b);
		test_stack_read(b);
        return (0);
}