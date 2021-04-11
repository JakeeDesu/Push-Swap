/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 07:02:01 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/20 23:54:52 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		tst_swap_b(t_elem *b)
{
	if (b && b->next && b->nb < b->next->nb)
		return (1);
	return (0);
}

int		tst_rot_b(t_elem *b, t_info info, int up)
{
	t_elem	*e;
	int		l;

	e = b;
	l = 0;
	while (e)
	{
		l++;
		e = e->next;
	}
	e = b;
	if ((l == info.lb) && e && e->next)
	{
		while (e->next)
			e = e->next;
		if (up && b->nb < e->nb)
			return (1);
		if (!up && b->nb > e->nb)
			return (1);
	}
	return (0);
}
