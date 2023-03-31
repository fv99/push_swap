/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:47:57 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/03/31 15:57:35 by fvonsovs         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		you_fucked_up("Invalid number of arguments");
	else
	{
		a = (t_stack **)malloc(sizeof(t_stack));
		b = (t_stack **)malloc(sizeof(t_stack));
		b = NULL;
		initialize_list(a ,argc, argv);
		test_stack_read(a);
		test_sa_sb(a);
		test_pa_pb(a, b);
		test_ss(a, b);
		test_stack_read(b);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}