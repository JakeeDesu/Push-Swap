/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 07:15:04 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/20 23:48:45 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min(t_elem *a, t_info *info)
{
	t_elem *e;

	e = a;
	if (a)
		info->min = a->nb;
	while (e)
	{
		if (e->nb < info->min)
			info->min = e->nb;
		e = e->next;
	}
}

t_info	init_info(t_elem *a, int length)
{
	int		i;
	int		l;
	t_elem	*e;
	t_info	info;

	info.empty = 1;
	l = 0;
	info.max = a->nb;
	info.min = a->nb;
	info.mid = a->nb;
	e = a;
	i = 0;
	while (e && l < length)
	{
		l++;
		if (e->nb >= info.max)
			info.max = e->nb;
		if (e->nb <= info.min)
			info.min = e->nb;
		e = e->next;
	}
	return (info);
}

void	pick_mid(t_info *info, t_elem *a, int length)
{
	t_elem	*e;
	t_elem	*e2;
	int		i;

	e2 = a;
	i = 0;
	while (i != info->lb)
	{
		e = a;
		length = info->l;
		while (e && length > 0)
		{
			length--;
			if (e->nb < info->mid)
				i++;
			e = e->next;
		}
		if (i != info->lb)
		{
			e2 = e2->next;
			info->mid = e2->nb;
			i = 0;
		}
	}
}

t_info	get_info(t_elem *a, int length)
{
	t_elem	*e;
	t_info	info;
	int		l;

	if (a)
	{
		info = init_info(a, length);
		l = 0;
		e = a;
		while (e)
		{
			l++;
			e = e->next;
		}
		info.l = l;
		info.la = length;
		info.lb = length - ((length % 2 == 0) ? length / 2 : (length / 2) + 1);
		if (info.l > 2)
			pick_mid(&info, a, length);
		else if (info.l == 2)
			info.mid = (a->nb > a->next->nb) ? a->next->nb : a->nb;
	}
	else
		info.empty = 0;
	return (info);
}
