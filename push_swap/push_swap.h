/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:45:04 by yiken             #+#    #+#             */
/*   Updated: 2024/03/07 10:22:04 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				is_above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**ft_split(char **av, int ac, char sep);
void			cr_stack(t_stack_node **a, char **av);
int				is_syntax_err(char *str);
int				is_repetition_err(t_stack_node *stack, int nbr);
void			heap_clean(t_stack_node **stack, char **av);
void			free_av(char **av);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **stack, int nbr);
int				get_stack_len(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);
t_stack_node	*get_major_node(t_stack_node *stack);
t_stack_node	*get_minor_node(t_stack_node *stack);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
int				is_not_sorted(t_stack_node *stack);
void			short_sort(t_stack_node **a);
void			promote_node(t_stack_node **stack,
					t_stack_node *top_node, bool swapped);
void			init_nodes(t_stack_node *a, t_stack_node *b, bool swapped);
void			long_sort(t_stack_node **a, t_stack_node **b);
void			set_current_position(t_stack_node *stack);
void			reduce_price(t_stack_node *a, int stack_a_len,
					int stack_b_len, bool is_above_median);
void			rev_set_target_node(t_stack_node *a, t_stack_node *b);

#endif