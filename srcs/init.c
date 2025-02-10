/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:27:28 by huahmad           #+#    #+#             */
/*   Updated: 2025/02/10 14:54:36 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void init_nodes_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest(a);
}

void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}

static void append_node(t_stack_node **st, int n)
{
    t_stack_node    *node;
    t_stack_node    *last_node;
    
    if(!st)
        return ;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->nbr = n;
    if (!(*st))
    {
        *st = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last(*st);
        last_node->next = node;
        node->prev = last_node;
    }
}

void init_a(t_stack_node **a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while(argv[i])
    {
        if(error_syntax(argv[i]))
            free_errors(a);
        n = ft_atoi(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if  (error_duplicate(*a, (int)n))
            free_errors(a);
        append_node(a, (int)n);
        i++;
    }
}
