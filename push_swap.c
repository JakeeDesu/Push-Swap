/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 04:05:48 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 11:00:14 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		a_length(t_elem *e)
{
	int i;

	i = 0;
	while (e)
	{
		i++;
		e = e->next;
	}
	return (i);
}

void	if_empty(t_elem *a, t_memo **memo)
{
	if (!a)
	{
		free_memo(memo);
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	t_inst	*list;
	t_info	info;
	t_memo	*memo;

	a = NULL;
	list = NULL;
	memo = NULL;
	if (argc > 1)
	{
		if (fill_stack(&a, argc, argv, &memo))
		{
			if_empty(a, &memo);
			swap_stack(&a, &memo);
			info = get_info(a, a_length(a));
			x_sort(&list, &a, &b, info);
			show_instructions(list);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	free_memo(&memo);
	return (0);
}
