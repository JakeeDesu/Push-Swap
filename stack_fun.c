/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fun.                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 04:41:40 by hmhindat          #+#    #+#             */
/*   Updated: 2019/07/23 16:08:29 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pop(t_elem **stack)
{
	int		ret;
	t_elem	*del;

	ret = 0;
	if (stack && *stack)
	{
		ret = (*stack)->nb;
		del = (*stack)->next;
		search_elem_and_put_null((*stack)->nb, (*stack)->memo);
		free(*stack);
		*stack = del;
	}
	else
	{
		ft_putstr("pop : void arg or empty stack\n");
		exit(0);
	}
	return (ret);
}

void	push(t_elem **stack, int n, t_memo **memo)
{
	t_elem *n_elem;

	n_elem = (t_elem*)alloc_memo(sizeof(t_elem), memo, 1);
	n_elem->memo = memo;
	n_elem->nb = n;
	n_elem->next = NULL;
	if (stack == NULL)
	{
		ft_putstr("push : void arg\n");
		exit(0);
	}
	if (*stack == NULL)
		*stack = n_elem;
	else
	{
		n_elem->next = *stack;
		*stack = n_elem;
	}
}

int		peek(t_elem *stack)
{
	if (stack)
		return (stack->nb);
	ft_putstr("peek : void stack\n");
	exit(0);
}

void	free_stack(t_elem **stack)
{
	t_elem *e;

	if (stack)
	{
		while (*stack)
		{
			e = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = e;
		}
	}
}

void	show_stack(t_elem *stack)
{
	ft_putstr("\n------\n");
	while (stack)
	{
		ft_putnbr(stack->nb);
		ft_putchar('\n');
		stack = stack->next;
	}
	ft_putstr("NULL\n------\n\n");
}
