/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:40:32 by hmhindat          #+#    #+#             */
/*   Updated: 2019/08/04 04:15:29 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fill_stack(t_elem **a, int argc, char **argv, t_memo **memo)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	args = NULL;
	while (i < argc)
	{
		if ((args = split_shit(argv[i], ' ', memo)))
		{
			j = 0;
			while (args[j])
			{
				if (!is_int(args[j]))
					return (0);
				push(a, ft_atoi(args[j++]), memo);
			}
		}
		else
			return (0);
		i++;
	}
	if (is_dub(*a))
		return (1);
	return (0);
}

void	free_tab(void **data)
{
	char	**tab;
	int		i;

	tab = (char**)(*data);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(*data);
}
