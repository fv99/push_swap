/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:47:57 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/19 16:52:24 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// error handling
int	you_fucked_up(char *msg)
{
	ft_printf("\tERROR: %s\n", msg);
	exit(1);
}

// need long to check for MAX/MIN_INT
long	ft_atol(const char *s)
{
	int		i;
	long	res;
	long	coeff;

	i = 0;
	res = 0;
	coeff = 1;
	while (s[i] && (s[i] == ' '))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		coeff = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * coeff);
}

void	initialize_list(t_stack **lst, char **argv)
{
	t_stack	*tmp;
	char	**args;
	int		i;
	long	num;

	*lst = NULL;
	i = 1;
	args = argv;
	while (args[i])
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			you_fucked_up("Integer out of range");
		tmp = new_stack((int)num);
		stackadd_back(lst, tmp);
		i++;
	}
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
	return (0);
}
