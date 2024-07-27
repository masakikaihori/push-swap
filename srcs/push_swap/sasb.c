/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:03:49 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:01 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sasb(t_stack **stack, char c)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	if (stack == NULL || *stack == NULL || first->next == NULL)
		return ;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack = second;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b, char flag)
{
	sasb(stack_a, 'c');
	sasb(stack_b, 'c');
	if (flag == 'p')
		write(1, "ss\n", 3);
	return ;
}
