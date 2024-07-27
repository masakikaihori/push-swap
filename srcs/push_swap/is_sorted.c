/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:43:14 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/27 05:49:51 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_completely_sorted(t_stack **stack, char c)
{
	t_stack	*temp;
	int		num;

	if (*stack == NULL)
		return (0);
	temp = *stack;
	num = temp->num;
	temp = temp->next;
	while (temp != NULL)
	{
		if (c == 'a' && num > temp->num)
			return (0);
		if (c == 'd' && num < temp->num)
			return (0);
		num = temp->num;
		temp = temp->next;
	}
	return (1);
}

int	is_sorted(t_stack **stack, char c)
{
	int				big;
	int				small;
	int				check;
	unsigned int	index;

	big = biggest(stack);
	small = smallest(stack);
	check = 1;
	if (c == 'a')
	{
		index = get_index(stack, small);
		if (index == 0)
			is_completely_sorted(stack, c);
		check = is_a_sorted(small, stack);
	}
	else
	{
		index = get_index(stack, big);
		if (index == 0)
			is_completely_sorted(stack, c);
		check = is_b_sorted(big, stack);
	}
	return (check);
}

int	is_a_sorted(int small, t_stack **stack)
{
	int		i;
	t_stack	*top_node;
	t_stack	*node;

	top_node = *stack;
	node = get_node(stack, small);
	node = node->next;
	i = small;
	while (node != NULL)
	{
		if (i > node->num)
			return (0);
		i = node->num;
		node = node->next;
	}
	while (top_node->num != small)
	{
		if (i > top_node->num)
			return (0);
		i = top_node->num;
		top_node = top_node->next;
	}
	return (1);
}

int	is_b_sorted(int big, t_stack **stack)
{
	int		i;
	t_stack	*top_node;
	t_stack	*node;

	top_node = *stack;
	node = get_node(stack, big);
	node = node->next;
	i = big;
	while (node != NULL)
	{
		if (i < node->num)
			return (0);
		i = node->num;
		node = node->next;
	}
	while (top_node->num != big)
	{
		if (i < top_node->num)
			return (0);
		i = top_node->num;
		top_node = top_node->next;
	}
	return (1);
}
