/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:54:50 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 14:46:19 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	short_sort(t_stack_node **a)
{
	if (get_major_node(*a) == (*a))
		ra(a, false);
	else if (get_major_node(*a) == (*a)->next)
		rra(a, false);
	if ((*a)->next->value < (*a)->value)
		sa(a, false);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (get_stack_len(*a) > 3)
	{
		set_current_position(*a);
		promote_node(a, get_minor_node(*a), 'a');
		pb(b, a, false);
	}
}
