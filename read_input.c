/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:42:18 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 11:13:21 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_zero(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

int		return_val(char c, int i)
{
	if (c != '\n' && i)
		return (0);
	return (1);
}

int		read_input(t_inst **list, t_memo **memo)
{
	char	c;
	char	instruction[4];
	int		i;
	t_fun	fun;

	fill_zero(instruction, 4);
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (i > 3)
			return (0);
		if (c != '\n')
			instruction[i++] = c;
		else
		{
			fun = get_fun(instruction);
			if (!fun)
				return (0);
			add_inst(list, fun, memo);
			fill_zero(instruction, 4);
			i = 0;
		}
	}
	return (return_val(c, i));
}
