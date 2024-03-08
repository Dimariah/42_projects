/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:38:11 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 16:14:16 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = get_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	last_node->next->prev = last_node;
	(*head)->prev = 0;
	last_node->next->next = 0;
}

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
