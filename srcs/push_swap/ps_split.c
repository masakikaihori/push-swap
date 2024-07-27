/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaihori <mkaihori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:29:57 by mkaihori          #+#    #+#             */
/*   Updated: 2023/10/15 13:20:58 by mkaihori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		get_amount(char const *s);
static int		ps_isspace(char c);
static char		*make_str(char const *s);
static char		**make_strs(char const *s, char **strs);

char	**ps_split(char const *s)
{
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (get_amount(s) + 1));
	if (strs == NULL)
		return (NULL);
	strs[get_amount(s)] = NULL;
	strs = make_strs(s, strs);
	if (strs == NULL)
		return (NULL);
	return (strs);
}

static int	get_amount(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s != '\0' && (ps_isspace(*s)))
			s++;
		if (*s != '\0' && !(ps_isspace(*s)))
			count++;
		while (*s != '\0' && !(ps_isspace(*s)))
			s++;
	}
	return (count);
}

static int	ps_isspace(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

static char	**make_strs(char const *s, char **strs)
{
	int	index;

	index = 0;
	while (*s)
	{
		while (*s != '\0' && ps_isspace(*s))
			s++;
		if (*s != '\0' && !(ps_isspace(*s)))
		{
			strs[index] = make_str(s);
			if (strs[index] == NULL)
			{
				while (--index >= 0)
					free(strs[index]);
				free(strs);
				return (NULL);
			}
			index++;
		}
		while (*s != '\0' && !(ps_isspace(*s)))
			s++;
	}
	return (strs);
}

static char	*make_str(char const *s)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != '\0' && !(ps_isspace(s[len])))
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
		str[len] = s[len];
	return (str);
}

// #include<stdio.h>

// int main(void)
// {
// 	char *s = "with great power there must also come -- great responsibility!";
// 	char c = ' ';
// 	char **strs = ft_split(s, c);

// 	for (int i = 0; strs[i] != NULL; i++)
// 		printf("%s\n", strs[i]);
// 	return (0);
// }