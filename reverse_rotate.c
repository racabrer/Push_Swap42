/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:40:08 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/09 20:02:17 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.
rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
*/

void	reverse_rotate_node(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	prev_last = last->prev;
	if (prev_last)
		prev_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **a, bool checker)
{
	reverse_rotate_node(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	reverse_rotate_node(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate_node(a);
	reverse_rotate_node(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
