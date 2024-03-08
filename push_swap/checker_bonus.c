/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:19:34 by yiken             #+#    #+#             */
/*   Updated: 2024/03/08 10:52:05 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*action;

	a = 0;
	b = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	av = ft_split(av, ac, ' ');
	if (!av)
		return (1);
	cr_stack(&a, av + 1);
	action = get_next_line(0);
	sort_stack(&a, &b, action);
	check_sort(&a, &b);
	return (0);
}
