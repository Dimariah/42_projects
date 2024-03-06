/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rev_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:07:40 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 16:21:48 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = get_last_node(*head);
	last_node->prev->next = 0;
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = last_node;
	(*head)->prev = 0;
}

void	rra(t_stack_node **a, bool checker)
{
	rev_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	rev_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
