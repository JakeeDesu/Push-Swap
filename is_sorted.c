/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:45:51 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 10:03:14 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_elem *a, t_info info)
{
	t_elem	*e;
	int		i;

	if (a && a->next)
	{
		e = a;
		i = 1;
		while (i < info.la && e->next)
		{
			if (e->nb > e->next->nb)
				return (0);
			e = e->next;
			i++;
		}
	}
	return (1);
}
