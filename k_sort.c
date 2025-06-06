/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:27:50 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/06 17:51:29 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_k_size (int stack_size)
{
	if (stack_size <= 10)
		return (2);
	else if (stack_size <= 50)
		return	(5);
	else if (stack_size <= 100)
		return (10);
	else if (stack_size <= 500)
		return (20);
	else
		return (stack_size / 25);
}

int get_position (t_stack *stack, t_stack *target)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

t_stack *find_max(t_stack *stack)
{
	t_stack *max;

	max = stack;

	while (stack)
	{
		if(stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
	
}

void push_back_from_b(t_stack **a, t_stack **b)
{
    t_stack *max;
    int pos;

    while (*b)
    {
        max = find_max(*b);
        pos = get_position(*b, max);
        print_stack(*b);
        if (pos < stack_size(*b) / 2) 
        {
            while (pos-- > 0)
                rb(b, false);
        }
        else 
        {
            while (pos++ < stack_size(*b))
                rrb(b, false);
        }
        pa(a, b);
        print_stack(*a);
        print_stack(*b);
    }
}

void push_chunk_to_b (t_stack **a, t_stack **b, int *current_index, int k)
{
	t_stack *tmp;
	int pos;
	
	tmp = *a;
	pos = 0;
	while(tmp && !(tmp->index >= *current_index && tmp->index < *current_index + k))
	{
		tmp = tmp->next;
		pos++;
	}
	if (!tmp)
	{
		*current_index += k;
		return;
	}
	if (pos < stack_size(*a) / 2)
		while (pos-- > 0)
			ra(a, false);
	else
		while(pos++ < stack_size(*a))
			rra(a, false);
	pb(a, b);
}

void k_sort(t_stack **a, t_stack **b)
{
	int size;
	int k;
	int current_index;

	size = stack_size(*a);
	k = get_k_size(size);
	current_index = 0;
	while (*a)
		push_chunk_to_b(a, b, &current_index, k);
	push_back_from_b(a, b);
}
