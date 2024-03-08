/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:08:32 by yiken             #+#    #+#             */
/*   Updated: 2024/03/08 11:53:13 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_len;

	a = 0;
	b = 0;
	if (1 == ac || (ac == 2 && !av[1][0]))
		return (1);
	av = ft_split(av, ac, ' ');
	if (av)
		cr_stack(&a, av + 1);
	if (is_not_sorted(a))
	{
		stack_len = get_stack_len(a);
		if (stack_len == 2)
			sa(&a, false);
		else if (stack_len == 3)
			short_sort(&a);
		else
			long_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
