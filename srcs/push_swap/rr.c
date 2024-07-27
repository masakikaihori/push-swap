/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:03:34 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/27 06:02:06 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, char flag)
{
	rarb(stack_a, flag);
	rarb(stack_b, flag);
	if (flag == 'p')
		write(1, "rr\n", 3);
	return ;
}

void	rarb(t_stack **stack, char c)
{
	t_stack	*first_node;

	if (*stack == NULL)
		return ;
	first_node = *stack;
	*stack = first_node->next;
	first_node->next = NULL;
	ps_lstadd_back(stack, first_node);
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
	return ;
}
