/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:55:38 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 10:25:31 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_elem **a, t_elem **b)
{
	t_elem *e;

	if (b && *b && a)
	{
		if (*a == NULL)
		{
			*a = *b;
			*b = (*b)->next;
			(*a)->next = NULL;
		}
		else
		{
			e = *b;
			*b = (*b)->next;
			e->next = *a;
			*a = e;
		}
	}
}