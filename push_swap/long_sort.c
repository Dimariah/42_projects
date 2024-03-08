/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:55:54 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 13:28:27 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduce_price(t_stack_node *a, int stack_a_len,
	int stack_b_len, bool is_above_median)
{
	if (is_above_median)
	{
		if (a->current_position == a->target_node->current_position)
			a->push_price = a->current_position
				+ a->target_node->current_position / 2;
		else if (a->current_position > a->target_node->current_position)
			a->push_price = a->current_position;
		else
			a->push_price = a->target_node->current_position;
	}
	else
	{
		if (stack_a_len - a->current_position
			== stack_b_len - a->target_node->current_position)
			a->push_price = a->current_position
				+ a->target_node->current_position / 2;
		else if (stack_a_len - a->current_position
			> stack_b_len - a->target_node->current_position)
			a->push_price = stack_a_len - a->current_position;
		else
			a->push_price = stack_b_len - a->target_node->current_position;
	}
}

void	promote_node(t_stack_node **stack,
		t_stack_node *top_node, bool is_a)
{
	while (*stack != top_node)
	{
		if (is_a)
		{
			if (top_node->is_above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else
		{
			if (top_node->is_above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

void	insert_node(t_stack_node **a, t_stack_node **b, bool swapped)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*target_node;

	cheapest_node = get_cheapest(*a);
	target_node = cheapest_node->target_node;
	while (*a != cheapest_node && *b != target_node)
	{
		if (cheapest_node->is_above_median && target_node->is_above_median)
			rr(a, b, false);
		else if (!cheapest_node->is_above_median
			&& !target_node->is_above_median)
			rrr(a, b, false);
		else
			break ;
	}
	promote_node(a, cheapest_node, !swapped);
	promote_node(b, target_node, swapped);
	if (swapped)
		pa(b, a, false);
	else
		pb(b, a, false);
}

void	long_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*minor_node;

	while (get_stack_len(*b) < 2)
		pb(b, a, false);
	while (get_stack_len(*a) > 3)
	{
		init_nodes(*a, *b, false);
		insert_node(a, b, false);
	}
	short_sort(a);
	while (*b)
	{
		init_nodes(*a, *b, true);
		insert_node(b, a, true);
	}
	set_current_position(*a);
	minor_node = get_minor_node(*a);
	promote_node(a, get_minor_node(*a), true);
}
