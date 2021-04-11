/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 08:53:05 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 14:58:24 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_inst(t_inst *list, t_elem **stack, t_elem **stack2)
{
	t_fun	f;

	while (list)
	{
		if (!ft_strcmp(list->name, "pb"))
			f = pa;
		else if (!ft_strcmp(list->name, "pa"))
			f = pb;
		else
			f = list->f;
		f(stack, stack2);
		list = list->next;
	}
}
