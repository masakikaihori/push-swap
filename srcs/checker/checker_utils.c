/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:15 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/26 20:07:16 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	read_sort(t_stack **stack_a, t_stack **stack_b)
{
	char	op[5];
	ssize_t	byte;
	size_t	total;

	byte = 1;
	total = 0;
	while (byte > 0)
	{
		byte = read(0, op + total, 1);
		if (byte < 0)
			error_free2(stack_a, stack_b);
		if (byte == 0)
			return ;
		total += byte;
		op[total] = '\0';
		if (op[total - 1] == '\n' || total == 4)
		{
			op_sort(op, stack_a, stack_b);
			total = 0;
		}
	}
	return ;
}

void	op_sort(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ps_strcmp(op, "sa\n") == 0)
		sasb(stack_a, 'c');
	else if (ps_strcmp(op, "sb\n") == 0)
		sasb(stack_b, 'c');
	else if (ps_strcmp(op, "ss\n") == 0)
		ss(stack_a, stack_b, 'c');
	else if (ps_strcmp(op, "pa\n") == 0)
		papb(stack_b, stack_a, 'c');
	else if (ps_strcmp(op, "pb\n") == 0)
		papb(stack_a, stack_b, 'c');
	else if (ps_strcmp(op, "ra\n") == 0)
		rarb(stack_a, 'c');
	else if (ps_strcmp(op, "rb\n") == 0)
		rarb(stack_b, 'c');
	else if (ps_strcmp(op, "rr\n") == 0)
		rr(stack_a, stack_b, 'c');
	else if (ps_strcmp(op, "rra\n") == 0)
		rrarrb(stack_a, 'c');
	else if (ps_strcmp(op, "rrb\n") == 0)
		rrarrb(stack_b, 'c');
	else if (ps_strcmp(op, "rrr\n") == 0)
		rrr(stack_a, stack_b, 'c');
	else
		error_free2(stack_a, stack_b);
	return ;
}
