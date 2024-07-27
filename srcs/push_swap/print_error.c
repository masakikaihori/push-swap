/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:09:43 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 17:04:44 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*f_node;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	temp = *stack;
	while (temp != NULL)
	{
		f_node = temp;
		temp = temp->next;
		f_node->next = NULL;
		free(f_node);
	}
	return ;
}

void	error_free(t_stack **stack)
{
	free_stack(stack);
	print_error();
	return ;
}

void	error_free2(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	print_error();
	return ;
}
