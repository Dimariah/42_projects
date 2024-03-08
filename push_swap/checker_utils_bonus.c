/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:50:29 by yiken             #+#    #+#             */
/*   Updated: 2024/03/05 12:26:15 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] && s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	action_error(t_stack_node **a, t_stack_node **b, char *action)
{
	free(action);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	apply_action(t_stack_node **a, t_stack_node **b, char *action)
{
	if (!ft_strcmp(action, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(action, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(action, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(action, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(action, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(action, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(action, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(action, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(action, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(action, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(action, "rrr\n"))
		rrr(a, b, true);
	else
		action_error(a, b, action);
}

void	sort_stack(t_stack_node **a, t_stack_node **b, char *action)
{
	if (action)
	{
		apply_action(a, b, action);
		free(action);
		sort_stack(a, b, get_next_line(0));
	}
}

void	check_sort(t_stack_node **a, t_stack_node **b)
{
	if (!is_not_sorted(*a) && *b == 0)
	{
		free_stack(a);
		write(1, "OK\n", 3);
	}
	else
	{
		free_stack(a);
		free_stack(b);
		write(1, "KO\n", 3);
	}
}
