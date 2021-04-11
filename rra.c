/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 02:25:48 by hmhindat          #+#    #+#             */
/*   Updated: 2019/06/20 02:42:33 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_elem **a, t_elem **b)
{
	t_elem	*e;
	t_elem	*p;
	t_elem	**bb;

	bb = b;
	if (a && *a && (*a)->next)
	{
		p = *a;
		while (p->next->next)
			p = p->next;
		e = p->next;
		p->next = NULL;
		e->next = *a;
		*a = e;
	}
}
