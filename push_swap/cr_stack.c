/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:55:05 by yiken             #+#    #+#             */
/*   Updated: 2024/03/07 10:22:33 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*temp_a;
	long			best_match;

	while (b)
	{
		temp_a = a;
		best_match = 2147483648;
		while (temp_a)
		{
			if (temp_a->value > b->value && temp_a->value < best_match)
			{
				b->target_node = temp_a;
				best_match = temp_a->value;
			}
			if (best_match == 2147483648)
				b->target_node = get_minor_node(a);
			temp_a = temp_a->next;
		}
		b = b->next;
	}
}

long	ft_atol(char *str)
{
	int		sign;
	long	total;
	int		i;

	sign = 1;
	total = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
		total = total * 10 + str[i++] - '0';
	return (total * sign);
}

void	cr_stack(t_stack_node **stack, char **av)
{
	int		i;
	long	nbr;

	i = 0;
	while (av[i])
	{
		if (is_syntax_err(av[i]))
			heap_clean(stack, av);
		nbr = ft_atol(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			heap_clean(stack, av);
		if (is_repetition_err(*stack, (int)nbr))
			heap_clean(stack, av);
		append_node(stack, (int)nbr);
		i++;
	}
	free_av(av);
}
