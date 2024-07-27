/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:15:59 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 19:49:43 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_btoa(t_stack **stack_a, t_stack **stack_b)
{
	t_rotation	rot;

	while (stack_size(stack_b) > 0)
	{
		rot = find_way(stack_b, stack_a, 'b');
		push_to(stack_b, stack_a, rot, 'a');
	}
	if (!is_completely_sorted(stack_a, 'a'))
		rotate_stack(stack_a);
	return ;
}

void	rotate_stack(t_stack **stack)
{
	unsigned int	s_index;
	unsigned int	size;

	s_index = get_index(stack, smallest(stack));
	size = stack_size(stack);
	if (size / 2 > s_index)
	{
		while (s_index != 0)
		{
			rarb(stack, 'a');
			s_index--;
		}
	}
	else
	{
		while (s_index != size)
		{
			rrarrb(stack, 'a');
			s_index++;
		}
	}
	return ;
}
