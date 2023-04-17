/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:24:13 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/17 14:44:22 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (((argv[i] == '+') || (argv[i] == '-')) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

// compares strings ignoring + sign
int	string_compare(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

// checks for duplicates
int	check_dupes(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && !string_compare(argv[i], argv[j]))
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+') || (argv[i] == '-'))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char **argv)
{
	int	i;
	int	zeros;

	zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			you_fucked_up("Non-digits in input");
		zeros += is_zero(argv[i]);
		i++;
	}
	if (zeros > 1)
		you_fucked_up("Multiple zeros in input");
	if (check_dupes(argv))
		you_fucked_up("Duplicates in input");
	return(1);
}
