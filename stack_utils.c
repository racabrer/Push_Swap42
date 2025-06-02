/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:56:39 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/02 17:27:49 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int count;

    count = 0;
    if (NULL == stack)
		return (0);
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}
void push_smallest_to_b(t_stack **a, t_stack **b)
{
	t_stack *smallest;
	t_stack *current;
	int pos;
	int i;

	pos = 0;
	i = 0;
	smallest = *a;
	current = *a;
	while (current)
	{
		if (current->content <  smallest->content)
		{
			smallest = current;
			pos = i;
		}
		current = current->next;
		i++;
	}
	while (pos > 0)
	{
		ra(a, false);
		pos--;	
	}
	pb(a, b);
}

t_stack *find_smallest(t_stack *stack) 
{
	t_stack *smallest;
	t_stack *current;

    if (!stack)
		return NULL;
	smallest = stack;  
	current = stack;  
    while (current)  
    {
        if (current->content < smallest->content)  
            smallest = current;  
        current = current->next;
    }
    return (smallest);
}
/*
void assign_indexes(t_stack **stack)
{
	if (!stack || !*stack)
		return;
	t_stack *current;
    t_stack *smallest;
    int index;

	current = *stack;
	index = 0;
	while (index < stack_size(*stack))
	{
		smallest = NULL;
		t_stack *temp;

		temp = *stack;
		while (temp)
		{
			if((!smallest || temp->content < smallest->content) && temp->index == -1)
				smallest = temp;
			temp = temp->next;
		}
		if (smallest)
			smallest->index = index++;
	}
}
*/

