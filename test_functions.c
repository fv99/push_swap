/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:20:43 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/03/31 16:09:33 by fvonsovs         ###   ########.fr       */
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
    ft_printf("Initial stack:\n");
    test_stack_read(stack);
    sa_sb(stack, 0);
    ft_printf("After sa stack: \n");
    test_stack_read(stack);

    return (0);
}

int test_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\t Test ss:\n");
    ft_printf("Initial stack A:\n");
    test_stack_read(stack_a);
    ft_printf("Initial stack B:\n");
    test_stack_read(stack_b);
    ss(stack_a, stack_b);
    ft_printf("After ss stack A: ");
    test_stack_read(stack_a);
    ft_printf("After ss stack B: ");
    test_stack_read(stack_b);
    return (0);
}

int test_pa_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\t Test pa_pb:\n");
    ft_printf("Initial stack A:\n");
    test_stack_read(stack_a);
    ft_printf("Initial stack B:\n");
    test_stack_read(stack_b);

    pa_pb(stack_a, stack_b, 1);
    pa_pb(stack_a, stack_b, 0);

    ft_printf("After pa stack A:\n");
    test_stack_read(stack_a);
    ft_printf("After pb stack B:\n");
    test_stack_read(stack_b);

    return 0;
}