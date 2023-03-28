/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:48:10 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/03/28 16:23:16 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

// structs go here
typedef	struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
}	t_stack;




// push_swap.c

int	you_fucked_up(char *msg);

