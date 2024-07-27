/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:07:05 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 17:49:33 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_rotation
{
	int		push_num;
	int		below_num;
	long	times;
	int		how;
}	t_rotation;

typedef struct s_info
{
	unsigned int	from_index;
	unsigned int	to_index;
	unsigned int	from_size;
	unsigned int	to_size;
}	t_info;

void			push_swap(int ac, char *av[]);
void			set_stack_a(t_stack **stack_a, int ac, char *av[], char flag);
void			sort_two_nbr(char *av[]);
void			ps_lstadd_back(t_stack **stack_a, t_stack *new);
void			check_dep(t_stack **stack_a);
void			sort(t_stack **stack_a);
void			sort_atob(t_stack **stack_a, t_stack **stack_b);
void			ps_lstadd_front(t_stack **stack, t_stack *new);
void			papb(t_stack **stack_from, t_stack **stack_to, char to);
void			set_rotation(t_rotation *rot, int times, int a, int b);
void			rotation_times(t_info info, t_rotation *rot, int a, int b);
void			rr(t_stack **stack_a, t_stack **stack_b, char flag);
void			sort_btoa(t_stack **stack_a, t_stack **stack_b);
void			push_to(t_stack **stack_a, t_stack **stack_b,
					t_rotation rot, char c);
void			rotate_stack(t_stack **stack);
void			rrr(t_stack **stack_a, t_stack **stack_b, char flag);
void			rrup(t_stack **stack_from, t_stack **stack_to,
					t_rotation rot, char to);
void			rrrdown(t_stack **stack_from, t_stack **stack_to,
					t_rotation rot, char to);
void			updown(t_stack **stack_from, t_stack **stack_to,
					t_rotation rot, char to);
void			downup(t_stack **stack_from, t_stack **stack_to,
					t_rotation rot, char to);
void			rarb(t_stack **stack, char c);
void			rrarrb(t_stack **stack, char c);
void			sasb(t_stack **stack, char c);
void			ss(t_stack **stack_a, t_stack **stack_b, char flag);
void			free_stack(t_stack **stack);
void			error_free(t_stack **stack);
void			ac2case(char *av, t_stack **stack, char flag);
void			free_strs(char **strs);
void			is_one_strs(char **strs);
int				print_error(void);
int				biggest(t_stack **stack);
int				smallest(t_stack **stack);
int				tail_number(t_stack **stack);
int				find_place(int num, t_stack **stack, char c);
int				find_place_b(int num, t_stack **stack);
int				is_completely_sorted(t_stack **stack, char c);
int				is_b_sorted(int big, t_stack **stack);
int				is_a_sorted(int small, t_stack **stack);
int				is_sorted(t_stack **stack, char c);
unsigned int	stack_size(t_stack **stack);
unsigned int	get_index(t_stack **stack, int num);
long			ps_atoi(const char *str);
long			rrup_times(t_info info);
long			rrrdown_times(t_info info);
long			updown_times(t_info info);
long			downup_times(t_info info);
char			**ps_split(char const *s);
t_stack			*ps_lstnew(long num);
t_stack			*last_node(t_stack **stack);
t_stack			*newlast_node(t_stack **stack);
t_rotation		find_way(t_stack **stack_a, t_stack **stack_b, char c);
t_stack			*get_node(t_stack **stack, int i);

void			checker(int ac, char *av[]);
void			read_sort(t_stack **stack_a, t_stack **stack_b);
void			op_sort(char *op, t_stack **stack_a, t_stack **stack_b);
void			error_free2(t_stack **stack_a, t_stack **stack_b);
int				ps_strcmp(const char *s1, const char *s2);

#endif