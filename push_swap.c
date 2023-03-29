/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:47:57 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/03/28 17:24:01 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// error handling
int	you_fucked_up(char *msg)
{
	ft_printf("\tERROR: %s\n", msg);
	exit(1);
}

// list functions
t_stack	*new_stack(int val)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = val;
	stack->index = -1;
	stack->next = NULL;
	return(stack);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}


void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = stack_last(*stack);
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
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
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	// t_stack	**b;

	if (argc < 2)
		you_fucked_up("Invalid number of arguments");
	else
	{
		a = (t_stack **)malloc(sizeof(t_stack));
		// b = (t_stack **)malloc(sizeof(t_stack));
		initialize_list(a ,argc, argv);
		test_stack_read(a);
		// test_stack_read(b);
		free_stack(a);
		// free_stack(b);
	}
	return (0);
}