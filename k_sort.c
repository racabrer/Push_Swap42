/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:27:50 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/04 17:53:50 by racabrer         ###   ########.fr       */
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

void push_smallest_to_b (t_stack **a, t_stack **b)
{
	t_stack *smallest;
	t_stack *current;
	int pos;
	int i;

	smallest = *a;
	current = *a;
	pos = 0;
	i = 0;
	
	while(current)
	{
		if (current->content < smallest->content)
		{
			smallest = current;
			pos = i;
		}
		current = current->next;
		i++;
	}
	while (pos > 0)
	{
		ra (a, false);
		pos--;
	}
	pb(a, b);
}

t_stack *find_smallest(t_stack *a)
{
	t_stack *smallest;

	*smallest = *a;
	
	while (a)
	{
		if (a->content < smallest->content)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

int get_position (t_stack *a, t_stack *smallest)
{
	int pos;

	pos = 0;
	while (a)
	{
		if (a == smallest)
			return (pos);
		a = a->next;
		pos++;
	}
	return (pos);
}
 

