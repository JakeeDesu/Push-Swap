/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mamaciita_fill_memo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:29:09 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 15:35:21 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_memo(t_memo *n_memo, t_memo **memo, void *data, int type)
{
	t_memo	*p_memo;

	n_memo->type = type;
	n_memo->data = data;
	n_memo->next = NULL;
	if (!(*memo))
		*memo = n_memo;
	else
	{
		p_memo = *memo;
		while (p_memo->next)
			p_memo = p_memo->next;
		p_memo->next = n_memo;
	}
}
