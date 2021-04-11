/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_decision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:41:03 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 09:49:00 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		tst_swap(t_elem *a, t_info info)
{
	t_elem	*e;
	int		i;
	int		decide;

	if (info.la > 3 && a)
	{
		e = a;
		decide = 0;
		i = 0;
		while (i < info.la - 3)
		{
			i++;
			e = e->next;
		}
		if (e->nb > info.mid && e->next->nb > info.mid)
			if (e->next->next->nb > info.mid)
				decide = 1;
		e = a;
		if (e->next->nb <= info.mid && decide)
			return (1);
	}
	return (0);
}

int		tst_rotate(t_elem *a, t_info info)
{
	int		ret;
	int		up;
	int		down;
	int		i;

	i = 0;
	up = 0;
	down = 0;
	while (i < info.l && a)
	{
		if (a->nb < info.mid)
		{
			if (i < info.l / 2)
				up++;
			else
				down++;
		}
		i++;
		a = a->next;
	}
	ret = (up > down) ? 1 : 0;
	return (ret);
}

int		eq_stack(t_elem **a, t_info info)
{
	int		i;
	t_elem	*e;

	i = 0;
	e = *a;
	while (i < info.la)
	{
		if (e->nb > info.max)
			return (1);
		i++;
	}
	return (0);
}

t_fun	make_decision(t_elem **a, t_elem **b, t_info *info)
{
	if (a && b)
	{
		if (eq_stack(a, *info))
			return (&rra);
		if (info->la > 0 && (*a)->nb < info->mid)
		{
			(info->la)--;
			return (&pa);
		}
		if (tst_swap(*a, *info))
		{
			if (tst_swap_b(*b))
				return (&ss);
			else
				return (&sa);
		}
		else
		{
			if (tst_rotate(*a, *info))
				return (&ra);
			else
				return (&rra);
		}
	}
	return (NULL);
}
