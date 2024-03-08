/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:52:01 by yiken             #+#    #+#             */
/*   Updated: 2024/03/08 13:53:01 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "push_swap.h"
# include "get_next_line.h"

int		ft_strcmp(char *s1, char *s2);
void	action_error(t_stack_node **a, t_stack_node **b, char *action);
void	apply_action(t_stack_node **a, t_stack_node **b, char *action);
void	sort_stack(t_stack_node **a, t_stack_node **b, char *action);
void	check_sort(t_stack_node **a, t_stack_node **b);

#endif