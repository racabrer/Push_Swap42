/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:17:24 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/02 17:18:01 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initialize_indexes(t_stack **stack)
{
    t_stack *current = *stack;
    while (current)
    {
        current->index = -1;
        current = current->next;
    }
}

t_stack *find_smallest_unindexed(t_stack *stack)
{
    t_stack *smallest = NULL;
    t_stack *temp = stack;

    while (temp)
    {
        if ((!smallest || temp->content < smallest->content)
            && temp->index == -1)
            smallest = temp;
        temp = temp->next;
    }
    return (smallest);
}

void assign_indexes(t_stack **stack)
{
    int index;
    t_stack *smallest;

    if (!stack || !*stack)
        return;
    initialize_indexes(stack);
    index = 0;
    while (index < stack_size(*stack))
    {
        smallest = find_smallest_unindexed(*stack);
        if (smallest)
            smallest->index = index++;
    }
}
