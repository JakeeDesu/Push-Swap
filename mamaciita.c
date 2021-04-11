/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mamaciita.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:13:17 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 15:54:48 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_elem_and_put_null(int nb, t_memo **memo)
{
	t_memo	*p_memo;

	p_memo = *memo;
	while (p_memo)
	{
		if (p_memo->type == 1)
		{
			if (((t_elem*)(p_memo->data))->nb == nb)
			{
				p_memo->data = NULL;
				return ;
			}
		}
		p_memo = p_memo->next;
	}
}

void	free_memo(t_memo **mem)
{
	t_memo	*p_mem;
	t_memo	*s_mem;

	if (mem && *mem)
	{
		p_mem = *mem;
		while (p_mem)
		{
			s_mem = p_mem;
			p_mem = (p_mem)->next;
			if (s_mem->data)
			{
				if (s_mem->type == 1)
					free(s_mem->data);
				else if (s_mem->type == 3)
					free_tab(&(s_mem->data));
				else if (s_mem->type == 2)
				{
					free(((t_inst*)(s_mem->data))->name);
					free(s_mem->data);
				}
			}
			free(s_mem);
		}
	}
}

void	add_to_memo(void *data, t_memo **memo, int type)
{
	t_memo	*n_memo;

	if (!(n_memo = (t_memo*)malloc(sizeof(t_memo))))
	{
		free_memo(memo);
		if (data)
			free(data);
		exit(0);
	}
	if (memo)
		fill_memo(n_memo, memo, data, type);
	else
	{
		free(n_memo);
		if (data)
			free(data);
		exit(0);
	}
}

void	*alloc_memo(size_t size, t_memo **memo, int type)
{
	void	*mem;

	if (!(mem = malloc(size)))
	{
		free_memo(memo);
		exit(0);
	}
	add_to_memo(mem, memo, type);
	return (mem);
}

t_memo	*init_memo(t_memo **memo, t_inst **list, t_elem **a, t_elem **b)
{
	t_memo	*n_memo;

	if (!memo)
	{
		if (!(n_memo = (t_memo*)malloc(sizeof(t_memo))))
			exit(0);
		if (list)
			(*list)->memo = &n_memo;
		if (a)
			(*a)->memo = &n_memo;
		if (b)
			(*b)->memo = &n_memo;
		return (n_memo);
	}
	else
	{
		if (list)
			(*list)->memo = memo;
		if (a)
			(*a)->memo = memo;
		if (b)
			(*b)->memo = memo;
	}
	return (NULL);
}
