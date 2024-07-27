/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_times.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:43:39 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/24 21:32:01 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotation_times(t_info info, t_rotation *rot, int from, int to)
{
	if (rot->times < 0 || rrup_times(info) < rot->times)
	{
		set_rotation(rot, rrup_times(info), from, to);
		rot->how = 0;
	}
	if (rrrdown_times(info) < rot->times)
	{
		set_rotation(rot, rrrdown_times(info), from, to);
		rot->how = 1;
	}
	if (updown_times(info) < rot->times)
	{
		set_rotation(rot, updown_times(info), from, to);
		rot->how = 2;
	}
	if (downup_times(info) < rot->times)
	{
		set_rotation(rot, downup_times(info), from, to);
		rot->how = 3;
	}
	return ;
}

long	rrup_times(t_info info)
{
	long	times;

	if (info.from_index > info.to_index)
		times = info.from_index;
	else
		times = info.to_index;
	return (times);
}

long	rrrdown_times(t_info info)
{
	long	times;

	if (info.from_size - info.from_index > info.to_size - info.to_index)
		times = info.from_size - info.from_index;
	else
		times = info.to_size - info.to_index;
	return (times);
}

long	updown_times(t_info info)
{
	long	times;

	times = info.from_index + (info.to_size - info.to_index);
	return (times);
}

long	downup_times(t_info info)
{
	long	times;

	times = (info.from_size - info.from_index) + info.to_index;
	return (times);
}
