/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:44:10 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 19:46:38 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	sort_atob(stack_a, &stack_b);
	if (!is_sorted(stack_a, 'a'))
		sasb(stack_a, 'a');
	sort_btoa(stack_a, &stack_b);
	return ;
}
