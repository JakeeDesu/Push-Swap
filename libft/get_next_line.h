/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:20:42 by hmhindat          #+#    #+#             */
/*   Updated: 2019/01/22 00:15:26 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 10000

typedef	struct	s_buff_h
{
	int			fd;
	char		*lost;
}				t_buff_h;

int				get_next_line(const int fd, char **line);

#endif
