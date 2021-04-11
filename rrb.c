/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 02:25:48 by hmhindat          #+#    #+#             */
/*   Updated: 2019/06/20 02:43:23 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_elem **a, t_elem **b)
{
	t_elem	*e;
	t_elem	*p;
	t_elem	**aa;

	aa = a;
	if (b && *b && (*b)->next)
	{
		p = *b;
		while (p->next->next)
			p = p->next;
		e = p->next;
		p->next = NULL;
		e->next = *b;
		*b = e;
	}
}
