/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:25:16 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 15:20:36 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_fun	get_fun(char *name)
{
	if (ft_strcmp("sa", name) == 0)
		return (sa);
	if (ft_strcmp("sb", name) == 0)
		return (sb);
	if (ft_strcmp("ss", name) == 0)
		return (ss);
	if (ft_strcmp("ra", name) == 0)
		return (ra);
	if (ft_strcmp("rb", name) == 0)
		return (rb);
	if (ft_strcmp("rr", name) == 0)
		return (rr);
	if (ft_strcmp("pa", name) == 0)
		return (pa);
	if (ft_strcmp("pb", name) == 0)
		return (pb);
	if (ft_strcmp("rra", name) == 0)
		return (rra);
	if (ft_strcmp("rrb", name) == 0)
		return (rrb);
	if (ft_strcmp("rrr", name) == 0)
		return (rrr);
	return (NULL);
}

char	*strcmp_name(char **name, t_fun f)
{
	if (f == &sa && (*name = ft_strdup("sa")))
		return (*name);
	else if (f == &sb && (*name = ft_strdup("sb")))
		return (*name);
	else if (f == &ss && (*name = ft_strdup("ss")))
		return (*name);
	else if (f == &pa && (*name = ft_strdup("pa")))
		return (*name);
	else if (f == &pb && (*name = ft_strdup("pb")))
		return (*name);
	else if (f == &ra && (*name = ft_strdup("ra")))
		return (*name);
	else if (f == &rb && (*name = ft_strdup("rb")))
		return (*name);
	else if (f == &rr && (*name = ft_strdup("rr")))
		return (*name);
	else if (f == &rra && (*name = ft_strdup("rra")))
		return (*name);
	else if (f == &rrb && (*name = ft_strdup("rrb")))
		return (*name);
	else if (f == &rrr && (*name = ft_strdup("rrr")))
		return (*name);
	else
		return (NULL);
}

char	*get_name(t_fun f, t_memo **memo)
{
	char *name;

	if ((name = strcmp_name(&name, f)))
		return (name);
	else
	{
		free_memo(memo);
		exit(0);
	}
	return (NULL);
}
