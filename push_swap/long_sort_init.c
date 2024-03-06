/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:08:52 by yiken             #+#    #+#             */
/*   Updated: 2024/03/03 11:44:00 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = get_stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*temp_b;

	while (a)
	{
		best_match = -2147483649;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->value < a->value && temp_b->value > best_match)
			{
				best_match = temp_b->value;
				a->target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match == -2147483649)
			a->target_node = get_major_node(b);
		a = a->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	stack_b_len;
	int	stack_a_len;

	stack_b_len = get_stack_len(b);
	stack_a_len = get_stack_len(a);
	while (a)
	{
		if (a->is_above_median && a->target_node->is_above_median)
		{
			reduce_price(a, stack_a_len, stack_b_len, true);
		}
		else if (!a->is_above_median && !a->target_node->is_above_median)
			reduce_price(a, stack_a_len, stack_b_len, false);
		else
		{
			a->push_price = a->current_position;
			if (!a->is_above_median)
				a->push_price = stack_a_len - a->current_position;
			if (a->target_node->is_above_median)
				a->push_price += a->target_node->current_position;
			else
				a->push_price += stack_b_len - a->target_node->current_position;
		}
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	int				best_match_value;
	t_stack_node	*best_match_node;

	if (!stack)
		return ;
	best_match_value = stack->push_price;
	best_match_node = stack;
	while (stack)
	{
		if (stack->next && (stack->next->push_price < best_match_value))
		{
			best_match_value = stack->next->push_price;
			best_match_node = stack->next;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b, bool swapped)
{
	set_current_position(a);
	set_current_position(b);
	if (swapped)
	{
		rev_set_target_node(a, b);
		set_price(b, a);
		set_cheapest(b);
	}
	else
	{
		set_target_node(a, b);
		set_price(a, b);
		set_cheapest(a);
	}
}
