/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:08:25 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/09 19:55:48 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if (*a && (*a)->next && !is_sorted(*a))
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, false);
	}
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second > third)
	{
		sa(a, false);
		rra(a, false);
	}
	else if (first > third && third > second)
		ra(a, false);
	else if (second > first && first > third)
		sa(a, false);
	else if (second > third && third > first)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (first > second && third > first)
		rra(a, false);
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	push_smallest_to_b(a, b);
	sort_three(a);
	if (*b && (*b)->next && (*b)->content > (*b)->next->content)
		sb(b, false);
	while (*b)
		pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	if (*b && (*b)->next && (*b)->index < (*b)->next->index)
		sb(b, false);
	while (*b)
		pa(a, b);
}
