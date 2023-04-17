/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:28:48 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 17:49:53 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_ops(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa_sb(stack_a, 1);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sa_sb(stack_b, 0);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa_pb(stack_a, stack_b, 1);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pa_pb(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra_rb(stack_a, stack_b, 1);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		ra_rb(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		ra_rb(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra_rrb(stack_a, stack_b, 1);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rra_rrb(stack_a, stack_b, 0);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else
		you_fucked_up("Incorrect operation");
	return (0);
}

int	check_ops(t_stack **stack_a, t_stack **stack_b)
{
	char	*buf;

	buf = get_next_line(STDIN_FILENO);
	while (buf)
	{
		read_ops(stack_a, stack_b, buf);
		free(buf);
		buf = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(*stack_a))
	{
		ft_printf("OK\n");
		return (1);
	}
	else
		ft_printf("KO\n");
	free(buf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		you_fucked_up("Invalid number of arguments");
	else
	{
		check_input(argv);
		stack_a = NULL;
		stack_b = NULL;
		initialize_list(&stack_a, argc, argv);
		check_ops(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
