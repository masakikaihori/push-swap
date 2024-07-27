/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:03:11 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/26 20:05:17 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(int ac, char *av[])
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac == 1)
		exit(0);
	set_stack_a(&stack_a, ac, av, 'p');
	if (!is_completely_sorted(&stack_a, 'a'))
	{
		if (is_sorted(&stack_a, 'a'))
			rotate_stack(&stack_a);
		else
			sort(&stack_a);
	}
	free_stack(&stack_a);
	return ;
}

int	main(int ac, char *av[])
{
	push_swap(ac, av);
	return (0);
}

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q push_swap");
//}

//#include<stdio.h>
//void	print_stack(t_stack **stack)
//{
//	t_stack	*temp;

//	temp = *stack;
//	if (temp == NULL)
//		printf("empty\n");
//	while (temp != NULL)
//	{
//		printf("%ld\n", temp->num);
//		temp = temp->next;
//	}
//	return ;
//}

//void	check_stack(t_stack **stack_a, t_stack **stack_b)
//{
//	printf("stack_a\n");
//	print_stack(stack_a);
//	printf("stack_b\n");
//	print_stack(stack_b);
//	return ;
//}
