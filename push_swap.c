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

t_list	*initialize_list(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	int		num;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			you_fucked_up("Integer read failure");
		tmp = ft_lstnew((void *)(intptr_t)num);
		if (tmp == NULL)
			you_fucked_up("Failed to allocate list");
		ft_lstadd_back(&lst, tmp);
		i++;
	}
	return (lst);
}


void	test_list_read(t_list *lst)
{
	t_list	*buf;

	buf = lst;
	while (buf != NULL)
	{
		ft_printf("%s ", (char *) buf->content);
		buf = buf->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	ft_printf("Hello world! %s", argv[1]);
	if (argc < 2)
		you_fucked_up("Invalid number of arguments");
	else
	{
		stack = initialize_list(argc, argv);
		test_list_read(stack);

	}
	return (0);
}