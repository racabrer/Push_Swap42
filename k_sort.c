/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:27:50 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/11 18:34:44 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_k_size(int stack_size)
{
	if (stack_size <= 10)
		return (2);
	else if (stack_size <= 50)
		return (5);
	else if (stack_size <= 100)
		return (20);
	else if (stack_size <= 500)
		return (40);
	else
		return (stack_size / 25);
}

int	get_position(t_stack *stack, t_stack *target)
{
	int	pos;

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

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	rb_stack(t_stack **b, int num)
{
	while (num > 0)
	{
		rb(b, false);
		num--;
	}
}

void	push_back_from_b(t_stack **a, t_stack **b, int k)
{
	t_stack	*max;
	int		pos;
	int		num;
	int		max_index;

	num = k / 2;
	max_index = find_max(*b)->index;
	while (*b)
	{
		max = find_max(*b);
		if ((*b)->index < max_index - k / 2)
		{
			rb_stack(b, num);
			max_index -= k;
		}
		pos = get_position(*b, max);
		if (pos < stack_size(*b) / 2)
			while (pos-- > 0)
				rb(b, false);
		else
			while (pos++ < stack_size(*b))
				rrb(b, false);
		pa(a, b);
	}
}

t_stack 	*look_tmp(t_stack *tmp, int *current_index, int *pos, int k)
{
	while (tmp && !(tmp->index >= *current_index && tmp->index < *current_index
		+ k))
	{
		tmp = tmp->next;
		(*pos)++;
	}
	return(tmp);
}

void	push_chunk_to_b(t_stack **a, t_stack **b, int *current_index, int k)
{
	t_stack	*tmp;
	int		pos;
	t_stack	*max;

	tmp = *a;
	pos = 0;
	max = find_max(*a);
	tmp = look_tmp(tmp, current_index, &pos, k); 
	if (!tmp)
	{
		*current_index += k;
		return ;
	}
	else if (pos < stack_size(*a) / 2)
		while (pos-- > 0)
			ra(a, false);
	else
		while (pos++ < stack_size(*a))
			rra(a, false);
	pb(a, b);
	if (tmp->index >= *current_index + (k / 2) && tmp->index <= *current_index
		+ k)
		rb(b, false);
}

void	k_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	k;
	int	current_index;

	size = stack_size(*a);
	k = get_k_size(size);
	current_index = 0;
	print_stack(*a);
	while (*a)
		push_chunk_to_b(a, b, &current_index, k);
	print_stack(*b);
	push_back_from_b(a, b, 20);
	print_stack(*a);
}
