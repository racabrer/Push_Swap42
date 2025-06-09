/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:17:24 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/09 19:50:46 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_indexes(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

t_stack	*find_smallest_unindexed(t_stack *stack)
{
	t_stack	*smallest;

	smallest = NULL;
	while (stack)
	{
		if (stack->index == -1 && (!smallest
				|| stack->content < smallest->content))
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	assign_indexes(t_stack **stack)
{
	int		size;
	int		index;
	t_stack	*smallest;

	if (!stack || !*stack)
		return ;
	initialize_indexes(stack);
	index = 0;
	size = stack_size(*stack);
	while (index < size)
	{
		smallest = find_smallest_unindexed(*stack);
		if (smallest)
		{
			smallest->index = index++;
			printf("Valor %d -> índice %d\n", smallest->content,
				smallest->index);
		}
	}
}
