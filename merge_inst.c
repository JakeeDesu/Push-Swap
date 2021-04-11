/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:40:02 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/21 00:16:46 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_and_apply(t_inst **list, t_elem **a, t_elem **b, t_fun f)
{
	add_inst(list, f, (*a)->memo);
	f(a, b);
}

t_inst	*m1(t_inst **s_x, t_elem **a, t_elem **b)
{
	t_inst *list;

	list = NULL;
	if (ft_strcmp((s_x[0])->name, "pa") && ft_strcmp((s_x[1])->name, "pb"))
	{
		add_and_apply(&list, a, b, (s_x[0])->f);
		add_and_apply(&list, a, b, (s_x[1])->f);
	}
	else if (ft_strcmp((s_x[0])->name, "sa") && ft_strcmp((s_x[1])->name, "sb"))
		add_and_apply(&list, a, b, ss);
	else if (ft_strcmp((s_x[0])->name, "ra") && ft_strcmp((s_x[1])->name, "rb"))
		add_and_apply(&list, a, b, rr);
	else if (ft_strcmp((s_x[0])->name, "rra") &&
		ft_strcmp((s_x[1])->name, "rrb"))
		add_and_apply(&list, a, b, rrr);
	return (list);
}

void	merge_inst(t_inst **list, t_inst **s_x, t_elem **a, t_elem **b)
{
	if (s_x)
	{
		if (s_x[0] || s_x[1])
		{
			if ((s_x[0]) && (s_x[1]) && (s_x[0])->name == (s_x[1])->name)
				*list = m1(s_x, a, b);
			else
			{
				if (s_x[0])
				{
					add_inst(list, (s_x[0])->f, (*a)->memo);
					(s_x[0])->f(a, b);
				}
				if (s_x[1])
				{
					add_inst(list, (s_x[1])->f, (*a)->memo);
					(s_x[1])->f(a, b);
				}
			}
		}
		if (s_x[0])
			s_x[0] = (s_x[0])->next;
		if (s_x[1])
			s_x[1] = (s_x[1])->next;
	}
}
