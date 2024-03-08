/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:55:16 by yiken             #+#    #+#             */
/*   Updated: 2024/02/25 11:11:27 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = 0;
	node->value = nbr;
	if (!(*stack))
	{
		node->prev = 0;
		*stack = node;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	get_stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack_node	*get_major_node(t_stack_node *stack)
{
	t_stack_node	*highest_node;

	highest_node = stack;
	while (stack)
	{
		if (stack->next && (stack->next->value > highest_node->value))
			highest_node = stack->next;
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*get_minor_node(t_stack_node *stack)
{
	t_stack_node	*minor_node;

	minor_node = stack;
	while (stack)
	{
		if (stack->next && (stack->next->value < minor_node->value))
			minor_node = stack->next;
		stack = stack->next;
	}
	return (minor_node);
}
