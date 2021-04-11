/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:33:32 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/21 00:06:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		s3b(t_inst **list, t_elem **b)
{
	if ((*b)->nb > (*b)->next->nb)
	{
		if ((*b)->nb > (*b)->next->next->nb)
		{
			if ((*b)->next->nb < (*b)->next->next->nb)
			{
				add_inst(list, sb, (*b)->memo);
				add_inst(list, rb, (*b)->memo);
			}
		}
		else
		{
			add_inst(list, rrb, (*b)->memo);
		}
		return (0);
	}
	return (1);
}

t_inst	*sort_3b(t_elem **b)
{
	t_inst	*list;

	list = NULL;
	if (s3b(&list, b))
	{
		if ((*b)->nb > (*b)->next->next->nb)
		{
			add_inst(&list, sb, (*b)->memo);
		}
		else
		{
			if ((*b)->next->nb > (*b)->next->next->nb)
			{
				add_inst(&list, rb, (*b)->memo);
			}
			else
			{
				add_inst(&list, sb, (*b)->memo);
				add_inst(&list, rrb, (*b)->memo);
			}
		}
	}
	return (list);
}

int		s3pb(t_inst **list, t_elem **b)
{
	if ((*b)->nb > (*b)->next->nb)
	{
		if ((*b)->nb > (*b)->next->next->nb)
		{
			if ((*b)->next->nb < (*b)->next->next->nb)
			{
				add_inst(list, rb, (*b)->memo);
				add_inst(list, sb, (*b)->memo);
				add_inst(list, rrb, (*b)->memo);
			}
		}
		else
		{
			add_inst(list, rb, (*b)->memo);
			add_inst(list, sb, (*b)->memo);
			add_inst(list, rrb, (*b)->memo);
			add_inst(list, sb, (*b)->memo);
		}
		return (0);
	}
	return (1);
}

t_inst	*sort_3pb(t_elem **b)
{
	t_inst	*list;

	list = NULL;
	if (s3pb(&list, b))
	{
		if ((*b)->nb > (*b)->next->next->nb)
			add_inst(&list, sb, (*b)->memo);
		else
		{
			add_inst(&list, sb, (*b)->memo);
			add_inst(&list, rb, (*b)->memo);
			if ((*b)->next->nb > (*b)->next->next->nb)
			{
				add_inst(&list, sb, (*b)->memo);
				add_inst(&list, rrb, (*b)->memo);
			}
			else
			{
				add_inst(&list, sb, (*b)->memo);
				add_inst(&list, rrb, (*b)->memo);
				add_inst(&list, sb, (*b)->memo);
			}
		}
	}
	return (list);
}
