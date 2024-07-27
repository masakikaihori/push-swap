/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:43:56 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/24 19:08:21 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_rotation(t_rotation *rot, int times, int from, int to)
{
	rot->push_num = from;
	rot->below_num = to;
	rot->times = times;
	return ;
}
