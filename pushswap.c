/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:48:23 by huahmad           #+#    #+#             */
/*   Updated: 2025/02/10 14:31:50 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"                                                                           

int print_stack(t_stack_node *stack)
{
    ft_printf("\n");
    while (stack)
    {
        ft_printf("%d ", stack->nbr);
        stack = stack->next;
    }
    ft_printf("\n");
    return (0);
}

t_stack_node	*get_cheapest(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}






int	stack_len(t_stack_node *stack) 
{
	int	count;
	if (!stack) 
		return (0);
	count = 0;
	while (stack) 
    {
		stack = stack->next;
		count++;
	}
	return (count);
}




void prep_for_push(t_stack_node **stack, t_stack_node *target_node, char stack_name)
{
    while ((*stack != target_node))
    {
        if (stack_name == 'a')
        {
            if (target_node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if (stack_name == 'b')
        {
            if (target_node->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }    
}



static void move_a_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;
    
    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
        rev_rotate_both(a, b, cheapest_node);
    prep_for_push(a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node->target_node, 'b');
    pb(b, a, false);       
}

static void move_b_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b, false);
}

static void min_on_top(t_stack_node **a)
{
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if (find_min(*a)->above_median)
            ra(a, false);
        else 
            rra(a, false);
    }
}







void current_index(t_stack_node *stack)
{
    int i;
    int median;
    
    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}



void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;

    len_a = stack_len(*a);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    while (len_a-- > 3 && !stack_sorted(*a))
    {
        init_nodes_a(*a, *b);
        move_a_b(a, b);
    }
    sort_three(a);
    while(*b)
    {
        init_nodes_b(*a, *b);
        move_b_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}

void    sort_three(t_stack_node **a)
{
    t_stack_node *biggest_node;

    biggest_node = find_max(*a);
    if(biggest_node == *a)
        ra(a, false);
    else if ((*a)->next == biggest_node)
        rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);
}

bool    stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}





int main(int argc, char *argv[])
{
    t_stack_node *a;
    t_stack_node *b;
    
    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1); 
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    init_a(&a, argv + 1);
    if(!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else 
            sort_stacks(&a, &b);
    }
    free_stack(&a);
    return (0);
}
