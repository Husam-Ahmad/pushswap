/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:48:46 by huahmad           #+#    #+#             */
/*   Updated: 2025/03/17 14:22:49 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a);
void					free_split(char **split);

//***Stack initiation
void					init_a(t_stack_node **a, char **argv);

//***Nodes initiation
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_for_push(t_stack_node **s, t_stack_node *n,
							char c);

//***Stack utils
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);

//***Commands
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rotate(t_stack_node **stack);
void					move_a_b(t_stack_node **a, t_stack_node **b);

//***Algorithm
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					cost_analysis_a(t_stack_node *a, t_stack_node *b);
void					set_target_a(t_stack_node *a, t_stack_node *b);
void					set_target_b(t_stack_node *a, t_stack_node *b);

#endif
