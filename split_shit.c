/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:22 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 16:07:50 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nbr_words(const char *str, char c)
{
	int	i;
	int	j;
	int access;

	i = 0;
	j = 0;
	access = 1;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (access == 1))
		{
			j++;
			access = 0;
		}
		else if (str[i] == c)
			access = 1;
		i++;
	}
	return (j);
}

static int	nbr_letters(const char *str, char c)
{
	int	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != c))
	{
		i++;
	}
	return (i);
}

static int	fill_words(char *str1, char const *str2, char c, int n)
{
	int	i;

	i = 0;
	while ((str2[n] != c) && (str2[n] != '\0'))
		str1[i++] = str2[n++];
	str1[i] = '\0';
	while (str2[n] == c)
		n++;
	return (n);
}

void		init_i_t(int *i, int *t)
{
	*i = 0;
	*t = 0;
}

char		**split_shit(char const *s, char c, t_memo **memo)
{
	int		i;
	int		t;
	char	**tab;
	size_t	size;

	if (s)
	{
		size = sizeof(char*) * (nbr_words(s, c) + 1);
		tab = (char**)alloc_memo(size, memo, 3);
		init_i_t(&i, &t);
		while (s[i] == c)
			i++;
		while (s[i] != '\0')
		{
			size = sizeof(char) * (nbr_letters(s + i, c) + 1);
			if (!(tab[t] = (char*)malloc(sizeof(char) *
							(nbr_letters(s + i, c) + 1))))
				return (NULL);
			i = fill_words(tab[t++], s, c, i);
		}
		tab[t] = 0;
		return (tab);
	}
	else
		return (NULL);
}
