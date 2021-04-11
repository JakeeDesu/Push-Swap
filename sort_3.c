/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 09:49:27 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 10:59:37 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		s3(t_inst **list, t_elem **a)
{
	if ((*a)->nb > (*a)->next->nb)
	{
		if ((*a)->nb > (*a)->next->next->nb)
		{
			add_inst(list, ra, (*a)->memo);
			if ((*a)->next->nb > (*a)->next->next->nb)
				add_inst(list, sa, (*a)->memo);
		}
		else
			add_inst(list, sa, (*a)->memo);
		return (0);
	}
	return (1);
}

t_inst	*sort_3(t_elem **a)
{
	t_inst	*list;

	list = NULL;
	if (s3(&list, a))
	{
		if ((*a)->nb < (*a)->next->next->nb)
		{
			if ((*a)->next->nb > (*a)->next->next->nb)
			{
				add_inst(&list, sa, (*a)->memo);
				add_inst(&list, ra, (*a)->memo);
			}
		}
		else
			add_inst(&list, rra, (*a)->memo);
	}
	return (list);
}

int		s3p(t_inst **list, t_elem **a)
{
	if ((*a)->nb > (*a)->next->nb)
	{
		if ((*a)->nb > (*a)->next->next->nb)
		{
			add_inst(list, sa, (*a)->memo);
			add_inst(list, ra, (*a)->memo);
			add_inst(list, sa, (*a)->memo);
			add_inst(list, rra, (*a)->memo);
			if ((*a)->next->nb > (*a)->next->next->nb)
				add_inst(list, sa, (*a)->memo);
		}
		else
			add_inst(list, sa, (*a)->memo);
		return (0);
	}
	return (1);
}

t_inst	*sort_3p(t_elem **a)
{
	t_inst	*list;

	list = NULL;
	if (s3p(&list, a))
	{
		if ((*a)->nb > (*a)->next->next->nb)
		{
			add_inst(&list, ra, (*a)->memo);
			add_inst(&list, sa, (*a)->memo);
			add_inst(&list, rra, (*a)->memo);
			add_inst(&list, sa, (*a)->memo);
		}
		else
		{
			if ((*a)->next->nb > (*a)->next->next->nb)
			{
				add_inst(&list, ra, (*a)->memo);
				add_inst(&list, sa, (*a)->memo);
				add_inst(&list, rra, (*a)->memo);
			}
		}
	}
	return (list);
}
