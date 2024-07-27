/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac2case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:28 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/26 20:07:29 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ac2case(char *av, t_stack **stack, char flag)
{
	char			**strs;
	unsigned int	index;
	t_stack			*new;

	strs = ps_split(av);
	if (strs == NULL || strs[0] == NULL)
		print_error();
	if (strs[1] == NULL && flag == 'p')
		is_one_strs(strs);
	index = 0;
	while (strs[index] != NULL)
	{
		new = ps_lstnew(ps_atoi(strs[index]));
		if (!new)
		{
			free_strs(strs);
			error_free(stack);
		}
		ps_lstadd_back(stack, new);
		index++;
	}
	free_strs(strs);
	check_dep(stack);
	return ;
}

void	free_strs(char **strs)
{
	unsigned int	index;

	if (strs == NULL || *strs == NULL)
		return ;
	index = 0;
	while (strs[index] != NULL)
	{
		free(strs[index]);
		index++;
	}
	free(strs);
}

void	is_one_strs(char **strs)
{
	if (strs[1] == NULL && ps_atoi(strs[0]) != LONG_MAX)
	{
		free_strs(strs);
		exit(0);
	}
	else if (strs[1] == NULL && ps_atoi(strs[0]) == LONG_MAX)
	{
		free_strs(strs);
		print_error();
	}
	return ;
}
