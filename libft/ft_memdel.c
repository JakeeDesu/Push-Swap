/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 06:43:28 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/21 05:17:24 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	char	**str;

	if (ap)
	{
		str = (char**)ap;
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
	}
}
