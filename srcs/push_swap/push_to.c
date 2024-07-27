/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_1to2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:24:14 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 19:13:49 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_to(t_stack **stack_from,
	t_stack **stack_to, t_rotation rot, char to)
{
	if (rot.how == 0)
		rrup(stack_from, stack_to, rot, to);
	if (rot.how == 1)
		rrrdown(stack_from, stack_to, rot, to);
	if (rot.how == 2)
		updown(stack_from, stack_to, rot, to);
	if (rot.how == 3)
		downup(stack_from, stack_to, rot, to);
	if (to == 'a')
		papb(stack_from, stack_to, 'a');
	if (to == 'b')
		papb(stack_from, stack_to, 'b');
	return ;
}

void	rrup(t_stack **stack_from, t_stack **stack_to, t_rotation rot, char to)
{
	char	from;

	if (to == 'a')
		from = 'b';
	else if (to == 'b')
		from = 'a';
	while ((*stack_from)->num != rot.push_num
		&& (*stack_to)->num != rot.below_num)
		rr(stack_from, stack_to, 'p');
	if ((*stack_from)->num == rot.push_num)
	{
		while ((*stack_to)->num != rot.below_num)
			rarb(stack_to, to);
	}
	else if ((*stack_to)->num == rot.below_num)
	{
		while ((*stack_from)->num != rot.push_num)
			rarb(stack_from, from);
	}
	return ;
}

void	rrrdown(t_stack **stack_from,
	t_stack **stack_to, t_rotation rot, char to)
{
	char	from;

	if (to == 'a')
		from = 'b';
	else if (to == 'b')
		from = 'a';
	while ((*stack_from)->num != rot.push_num
		&& (*stack_to)->num != rot.below_num)
		rrr(stack_from, stack_to, 'p');
	if ((*stack_from)->num == rot.push_num)
	{
		while ((*stack_to)->num != rot.below_num)
			rrarrb(stack_to, to);
	}
	else if ((*stack_to)->num == rot.below_num)
	{
		while ((*stack_from)->num != rot.push_num)
			rrarrb(stack_from, from);
	}
	return ;
}

void	updown(t_stack **stack_from,
	t_stack **stack_to, t_rotation rot, char to)
{
	char	from;

	if (to == 'a')
		from = 'b';
	else if (to == 'b')
		from = 'a';
	while ((*stack_from)->num != rot.push_num)
		rarb(stack_from, from);
	while ((*stack_to)->num != rot.below_num)
		rrarrb(stack_to, to);
	return ;
}

void	downup(t_stack **stack_from, t_stack **stack_to,
	t_rotation rot, char to)
{
	char	from;

	if (to == 'a')
		from = 'b';
	else if (to == 'b')
		from = 'a';
	while ((*stack_from)->num != rot.push_num)
		rrarrb(stack_from, from);
	while ((*stack_to)->num != rot.below_num)
		rarb(stack_to, to);
	return ;
}
