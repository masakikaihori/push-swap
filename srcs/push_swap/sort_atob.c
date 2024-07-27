/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:44:05 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 19:08:42 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_atob(t_stack **stack_a, t_stack **stack_b)
{
	t_rotation	rot;

	if (stack_size(stack_a) == 4 && !is_sorted(stack_a, 'a'))
		papb(stack_a, stack_b, 'b');
	else if (stack_size(stack_a) >= 5 && !is_sorted(stack_a, 'a'))
	{
		papb(stack_a, stack_b, 'b');
		if (!is_sorted(stack_a, 'a'))
			papb(stack_a, stack_b, 'b');
	}
	while (stack_size(stack_a) > 3 && !is_sorted(stack_a, 'a'))
	{
		rot = find_way(stack_a, stack_b, 'a');
		push_to(stack_a, stack_b, rot, 'b');
	}
	return ;
}
