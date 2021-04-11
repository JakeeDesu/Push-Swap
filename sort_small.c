/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:44:36 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 11:08:19 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted_b(t_elem *b)
{
	t_elem *e;

	e = b;
	while (e->next)
	{
		if (e->nb < e->next->nb)
			return (0);
		e = e->next;
	}
	return (1);
}

int		sorted_a(t_elem *a)
{
	t_elem *e;

	e = a;
	while (e->next)
	{
		if (e->nb > e->next->nb)
			return (0);
		e = e->next;
	}
	return (1);
}

void	sort3_a(t_inst **list, t_elem **a, t_elem **b)
{
	if ((*a)->nb < (*a)->next->nb)
	{
		if ((*a)->nb > (*a)->next->next->nb)
			add_and_apply(list, a, b, rra);
		else
		{
			add_and_apply(list, a, b, rra);
			add_and_apply(list, a, b, sa);
		}
	}
	else
	{
		if ((*a)->next->nb > (*a)->next->next->nb)
		{
			add_and_apply(list, a, b, sa);
			add_and_apply(list, a, b, rra);
		}
		else
		{
			if ((*a)->next->next->nb > (*a)->nb)
				add_and_apply(list, a, b, sa);
			else
				add_and_apply(list, a, b, ra);
		}
	}
}

void	sort2(t_inst **list, t_elem **a, t_elem **b)
{
	t_inst	*s_b;
	t_inst	*e_x[2];
	int		a_l;
	int		b_l;

	s_b = NULL;
	if (!sorted_a(*a) && (a_l = list_length(*a)) == 2)
		add_and_apply(list, a, b, sa);
	if (!sorted_b(*b) && (b_l = list_length(*b)) == 2)
		add_and_apply(list, a, b, sb);
	if (!sorted_a(*a) && (a_l = list_length(*a)) == 3)
		sort3_a(list, a, b);
	if (!sorted_b(*b) && (b_l = list_length(*b)) == 3)
		s_b = sort_3b(b);
	e_x[0] = NULL;
	e_x[1] = s_b;
	merge_inst(list, e_x, a, b);
}

void	x_sort(t_inst **list, t_elem **a, t_elem **b, t_info info)
{
	t_fun	f;

	if (!sorted_a(*a) && (list_length(*a) == 4 || list_length(*a) == 5))
	{
		while (!(is_separated(*a, *b, info)))
		{
			f = make_decision(a, b, &info);
			add_and_apply(list, a, b, f);
		}
		sort2(list, a, b);
		while (*b)
			add_and_apply(list, a, b, pb);
	}
	else
		sort(list, a, b, info);
}
