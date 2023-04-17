/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:47:57 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 17:34:29 by fvonsovs         ###   ########.fr       */
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
