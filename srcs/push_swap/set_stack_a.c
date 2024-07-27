/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:25:24 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/17 22:20:35 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_stack_a(t_stack **stack_a, int ac, char *av[], char flag)
{
	int		index;
	t_stack	*new;

	index = 1;
	if (ac == 2)
		ac2case(av[1], stack_a, flag);
	else if (ac == 3 && flag == 'p')
		sort_two_nbr(av);
	else
	{
		while (index < ac)
		{
			new = ps_lstnew(ps_atoi(av[index]));
			if (!new)
				error_free(stack_a);
			ps_lstadd_back(stack_a, new);
			index++;
		}
	}
	check_dep(stack_a);
	return ;
}

void	sort_two_nbr(char *av[])
{
	long	first;
	long	second;

	first = ps_atoi(av[1]);
	second = ps_atoi(av[2]);
	if (first == LONG_MAX || second == LONG_MAX || first == second)
		print_error();
	if (first > second)
		write(1, "sa\n", 3);
	exit(0);
}

void	check_dep(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (stack == NULL || *stack == NULL)
		error_free(stack);
	temp1 = *stack;
	while (temp1->next != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->num == temp2->num)
				error_free(stack);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return ;
}
