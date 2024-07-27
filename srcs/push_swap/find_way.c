/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:43:23 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/24 21:26:36 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotation	find_way(t_stack **stack_from, t_stack **stack_to, char c)
{
	t_stack		*temp_from;
	t_rotation	rot;
	t_info		info;
	int			temp_below;

	temp_from = *stack_from;
	rot.times = -1;
	info.from_size = stack_size(stack_from);
	info.to_size = stack_size(stack_to);
	while (temp_from != NULL)
	{
		temp_below = find_place(temp_from->num, stack_to, c);
		info.from_index = get_index(stack_from, temp_from->num);
		info.to_index = get_index(stack_to, temp_below);
		rotation_times(info, &rot, temp_from->num, temp_below);
		if (rot.times == 0 || rot.times == 1)
			return (rot);
		temp_from = temp_from->next;
	}
	return (rot);
}

int	find_place(int num, t_stack **stack, char c)
{
	t_stack	*temp;
	int		biggest_num;
	int		smallest_num;

	temp = *stack;
	biggest_num = biggest(stack);
	smallest_num = smallest(stack);
	if (c == 'a')
	{
		if (num > biggest_num || num < smallest_num)
			return (biggest_num);
		else if (num > temp->num && num < tail_number(&temp))
			return (temp->num);
		while (temp->next != NULL)
		{
			if (num < temp->num && num > temp->next->num)
				return (temp->next->num);
			temp = temp->next;
		}
	}
	return (find_place_b(num, stack));
}

int	find_place_b(int num, t_stack **stack)
{
	t_stack	*temp;
	int		biggest_num;
	int		smallest_num;

	temp = *stack;
	biggest_num = biggest(stack);
	smallest_num = smallest(stack);
	if (num > biggest_num || num < smallest_num)
		return (smallest_num);
	else if (num < temp->num && num > tail_number(&temp))
		return (temp->num);
	while (!(num > temp->num && num < temp->next->num))
		temp = temp->next;
	return (temp->next->num);
}
