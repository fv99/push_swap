/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:47:57 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/16 17:38:32 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// error handling
int	you_fucked_up(char *msg)
{
	ft_printf("\tERROR: %s\n", msg);
	exit(1);
}

void	initialize_list(t_stack **lst, int argc, char **argv)
{
	t_stack	*tmp;
	char	**args;
	int		i;

	*lst = NULL;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = new_stack(ft_atoi(args[i]));
		stackadd_back(lst, tmp);
		i++;
	}
	if (argc == 2)
		free_split(args);
	update_index(*lst);
}

int	push_swap(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc <= 4)
		sort_three(stack_a, stack_b);
	else if (argc == 6)
		sort_five(stack_a, stack_b);
	else if (argc == 5 || argc > 6)
	 	sort_lots(stack_a, stack_b);
	return(0);
}

int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        you_fucked_up("Invalid number of arguments");
    else
    {
		stack_a = NULL;
		stack_b = NULL;
        initialize_list(&stack_a, argc, argv);
		test_stack_read(&stack_a);
        test_stack_read(&stack_b);
        push_swap(&stack_a, &stack_b, argc);
        test_stack_read(&stack_a);
        test_stack_read(&stack_b);
        // test_my_shit(a, b);
        free_stack(&stack_a);
        free_stack(&stack_b);
    }
    return (0);
}