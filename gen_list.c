/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 03:56:09 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 10:42:34 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_length(t_elem *l)
{
	int		i;
	t_elem	*e;

	e = l;
	i = 0;
	while (e)
	{
		i++;
		e = e->next;
	}
	return (i);
}

int		is_separated(t_elem *a, t_elem *b, t_info info)
{
	t_elem	*e;
	int		i;

	i = 0;
	e = a;
	while (i < info.la && e)
	{
		if (e->nb < info.mid || e->nb > info.max)
			return (0);
		e = e->next;
		i++;
	}
	i = 0;
	e = b;
	while (i < info.lb && e)
	{
		if (e->nb >= info.mid)
			return (0);
		e = e->next;
		i++;
	}
	return (1);
}

void	sort_a(t_inst **s_a, t_elem **a, t_info info)
{
	if (info.la == 3)
	{
		if (info.l == 3)
			*s_a = sort_3(a);
		else
			*s_a = sort_3p(a);
	}
	else if (info.la == 2)
		if ((*a)->nb > (*a)->next->nb)
			add_inst(s_a, sa, (*a)->memo);
}

void	last_sort(t_inst **list, t_elem **a, t_elem **b, t_info info)
{
	t_inst	*s_a;
	t_inst	*s_b;
	t_inst	*e_x[2];

	s_a = NULL;
	s_b = NULL;
	if (list_length(*b) == 3)
		s_b = sort_3b(b);
	else if (list_length(*b) > 3)
		s_b = sort_3pb(b);
	else if (list_length(*b) == 2)
		if ((*b)->nb < (*b)->next->nb)
			add_inst(&s_b, sb, (*a)->memo);
	sort_a(&s_a, a, info);
	e_x[0] = s_a;
	e_x[1] = s_b;
	while (e_x[0] || e_x[1])
		merge_inst(list, e_x, a, b);
}

void	sort(t_inst **list, t_elem **a, t_elem **b, t_info info)
{
	int		i;
	t_info	n_info;
	t_fun	f;

	if (info.l > 3 && !is_sorted(*a, info))
	{
		while (!(is_separated(*a, *b, info)))
		{
			f = make_decision(a, b, &info);
			add_and_apply(list, a, b, f);
		}
		n_info = get_info(*a, info.la);
		last_sort(list, a, b, info);
		sort(list, a, b, n_info);
		i = 0;
		while (i < info.lb)
		{
			add_and_apply(list, a, b, pb);
			i++;
		}
		n_info = get_info(*a, info.lb);
		sort(list, a, b, n_info);
	}
	else if (info.l <= 3 && !is_sorted(*a, info))
		last_sort(list, a, b, info);
}
