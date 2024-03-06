/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:07:23 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 14:41:47 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*top_node;

	if (!(*src))
		return ;
	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = 0;
	if (*dest)
	{
		top_node->next = *dest;
		*dest = top_node;
		(*dest)->next->prev = *dest;
	}
	else
	{
		top_node->next = 0;
		*dest = top_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
