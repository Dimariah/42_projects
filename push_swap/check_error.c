/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:55:00 by yiken             #+#    #+#             */
/*   Updated: 2024/03/07 10:21:39 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_syntax_err(char *str)
{
	int	i;

	i = 0;
	while (i == 0 || str[i])
	{
		if (i == 0 && (str[i] != '+' && str[i] != '-'
				&& (str[i] < '0' || str[i] > '9')))
			return (1);
		if (i == 0 && (str[i] == '+' || str[i] == '-') && !str[i + 1])
			return (1);
		if (i > 0 && (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_repetition_err(t_stack_node *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_av(char **av)
{
	int		i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = 0;
}

void	heap_clean(t_stack_node **stack, char **av)
{
	free_av(av);
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
