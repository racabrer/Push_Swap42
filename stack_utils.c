/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:56:39 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/09 20:03:34 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

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

void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	t_stack	*current;
	int		pos;
	int		i;

	pos = 0;
	i = 0;
	smallest = *a;
	current = *a;
	while (current)
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
		ra(a, false);
		pos--;
	}
	pb(a, b);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	if (!stack)
		return (NULL);
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

int	get_k_size(int stack_size)
{
	if (stack_size <= 10)
		return (2);
	if (stack_size <= 50)
		return (5);
	if (stack_size <= 100)
		return (10);
	if (stack_size <= 500)
		return (20);
	return (25);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
