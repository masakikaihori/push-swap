/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:03:46 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/27 06:09:25 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b, char flag)
{
	rrarrb(stack_a, flag);
	rrarrb(stack_b, flag);
	if (flag == 'p')
		write(1, "rrr\n", 4);
	return ;
}

void	rrarrb(t_stack **stack, char c)
{
	t_stack	*bottom;
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	bottom = last_node(stack);
	temp = newlast_node(stack);
	temp->next = NULL;
	ps_lstadd_front(stack, bottom);
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	return ;
}

t_stack	*last_node(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*newlast_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*new_last;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	temp = *stack;
	new_last = NULL;
	while (temp->next != NULL)
	{
		new_last = temp;
		temp = temp->next;
	}
	return (new_last);
}
