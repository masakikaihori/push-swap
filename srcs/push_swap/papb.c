/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:03:23 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/27 05:56:26 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	papb(t_stack **stack_from, t_stack **stack_to, char to)
{
	t_stack	*push_node;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	push_node = *stack_from;
	*stack_from = push_node->next;
	push_node->next = NULL;
	ps_lstadd_front(stack_to, push_node);
	if (to == 'a')
		write(1, "pa\n", 3);
	if (to == 'b')
		write(1, "pb\n", 3);
	return ;
}
