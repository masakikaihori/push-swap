/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:07:08 by mkaihori          #+#    #+#             */
/*   Updated: 2024/04/27 05:56:38 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	checker(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	set_stack_a(&stack_a, ac, av, 'c');
	read_sort(&stack_a, &stack_b);
	if (is_completely_sorted(&stack_a, 'a') && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return ;
}

int	main(int ac, char *av[])
{
	checker(ac, av);
	return (0);
}

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q checker");
//}

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
