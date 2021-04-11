/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 23:23:31 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 09:00:23 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted(t_elem *a)
{
	while (a && a->next)
	{
		if (a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void	init_vars(t_elem **a, t_elem **b, t_inst **list, t_memo **memo)
{
	*a = NULL;
	*b = NULL;
	*list = NULL;
	*memo = NULL;
}

void	free_and_exit(t_memo **memo)
{
	free_memo(memo);
	exit(0);
}

void	apply_and_show(t_inst **list, t_elem **a, t_elem **b, t_memo **memo)
{
	swap_stack(a, memo);
	apply_inst(*list, a, b);
	if (sorted(*a) && !(*b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	t_inst	*list;
	t_memo	*memo;

	init_vars(&a, &b, &list, &memo);
	if (argc > 1)
	{
		if (!fill_stack(&a, argc, argv, &memo))
			ft_putstr_fd("Error\n", 2);
		else
		{
			if (a == NULL)
				free_and_exit(&memo);
			if (read_input(&list, &memo))
				apply_and_show(&list, &a, &b, &memo);
			else
				ft_putstr_fd("Error\n", 2);
		}
		free_memo(&memo);
	}
	return (0);
}
