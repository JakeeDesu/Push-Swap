/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 03:10:28 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/29 20:12:44 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	max_int(char *str, int sign)
{
	if (sign)
	{
		if (ft_strcmp("2147483648", str) < 0)
			return (0);
	}
	else
	{
		if (ft_strcmp("2147483647", str) < 0)
			return (0);
	}
	return (1);
}

int	is_int(char *str)
{
	int i;
	int l;
	int sign;

	sign = 0;
	if (*str == '-')
	{
		sign = 1;
		str++;
		if (!(*str))
			return (0);
	}
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit((int)str[i])))
			return (0);
		i++;
	}
	l = ft_strlen(str);
	if (l > 10)
		return (0);
	if (l == 10)
		return (max_int(str, sign));
	return (1);
}

int	is_dub(t_elem *stack)
{
	t_elem *e;

	while (stack && stack->next)
	{
		e = stack->next;
		while (e)
		{
			if (stack->nb == e->nb)
				return (0);
			e = e->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	valid_arg(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	i = 0;
	while (argv[i + 1])
	{
		j = i;
		while (argv[j + 1])
		{
			if (ft_strcmp(argv[i], argv[j + 1]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
