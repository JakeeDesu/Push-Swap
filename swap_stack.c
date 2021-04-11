/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:41:31 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/21 05:28:53 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	swap_stack(t_elem **stack, t_memo **memo)
{
	t_elem *e;

	if (stack)
	{
		e = NULL;
		while (*stack)
			push(&e, pop(stack), memo);
		*stack = e;
	}
}
