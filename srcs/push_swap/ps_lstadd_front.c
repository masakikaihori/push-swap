/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:07 by mkaihori          #+#    #+#             */
/*   Updated: 2023/10/06 08:53:00 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_lstadd_front(t_stack **stack, t_stack *new)
{
	if (stack == NULL || *stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
	return ;
}
