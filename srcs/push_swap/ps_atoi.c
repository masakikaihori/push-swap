/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:36:44 by mkaihori          #+#    #+#             */
/*   Updated: 2024/03/25 17:05:04 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long	make_result(int neg, const char *str, int i);
static long	get_abs(long min);

long	ps_atoi(const char *str)
{
	long	i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	result = make_result(neg, str, i);
	return (result);
}

static long	make_result(int neg, const char *str, int i)
{
	long	result;
	long	int_div_ten;
	long	max_mod_ten;
	long	min_mod_ten;

	int_div_ten = INT_MAX / 10;
	max_mod_ten = INT_MAX % 10;
	min_mod_ten = get_abs(INT_MIN % 10);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (neg == 1 && (result > int_div_ten
				|| ((result == int_div_ten) && (str[i] - '0') > max_mod_ten)))
			return (LONG_MAX);
		if (neg == -1 && (result > int_div_ten
				|| ((result == int_div_ten) && (str[i] - '0') > min_mod_ten)))
			return (LONG_MAX);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || str[0] == '\0')
		return (LONG_MAX);
	return (result * neg);
}

static long	get_abs(long min)
{
	if (min < 0)
		return (-min);
	return (min);
}
