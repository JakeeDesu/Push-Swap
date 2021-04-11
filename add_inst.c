/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:18:38 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 14:56:19 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		length(t_inst *l)
{
	int i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

void	add_inst(t_inst **list, t_fun f, t_memo **memo)
{
	t_inst	*e;
	t_inst	*l;

	if (list)
	{
		e = (t_inst*)alloc_memo(sizeof(t_inst), memo, 2);
		e->f = f;
		e->name = get_name(f, memo);
		e->memo = memo;
		e->next = NULL;
		if ((*list))
		{
			l = *list;
			while (l->next)
				l = l->next;
			e->memo = l->memo;
			l->next = e;
		}
		else
			*list = e;
	}
}

void	free_inst_list(t_inst **list, char c)
{
	t_inst	*p_list;
	char	s;

	s = c;
	if (list)
	{
		p_list = *list;
		while (*list)
		{
			p_list = (*list)->next;
			free((*list)->name);
			(*list)->name = NULL;
			free(*list);
			*list = NULL;
			*list = p_list;
		}
	}
}

void	show_instructions(t_inst *list)
{
	t_inst *e;

	e = list;
	while (e)
	{
		if (!ft_strcmp(e->name, "pb"))
			ft_putstr("pa");
		else if (!ft_strcmp(e->name, "pa"))
			ft_putstr("pb");
		else
			ft_putstr(e->name);
		ft_putchar('\n');
		e = e->next;
	}
}
