/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:43:27 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 17:46:40 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

unsigned int	get_index(t_stack **stack, int num)
{
	unsigned int	index;
	t_stack			*temp;

	index = 0;
	temp = *stack;
	while (temp->num != num)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

t_stack	*get_node(t_stack **stack, int i)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->num != i)
		temp = temp->next;
	return (temp);
}

int	biggest(t_stack **stack)
{
	int		biggest;
	t_stack	*temp;

	temp = *stack;
	biggest = temp->num;
	temp = temp->next;
	while (temp != NULL)
	{
		if (biggest < temp->num)
			biggest = temp->num;
		temp = temp->next;
	}
	return (biggest);
}

int	smallest(t_stack **stack)
{
	int		smallest;
	t_stack	*temp;

	temp = *stack;
	smallest = temp->num;
	temp = temp->next;
	while (temp != NULL)
	{
		if (smallest > temp->num)
			smallest = temp->num;
		temp = temp->next;
	}
	return (smallest);
}
