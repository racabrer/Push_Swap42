/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:39:27 by racabrer          #+#    #+#             */
/*   Updated: 2025/05/29 19:39:53 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
*/

void rotate_node(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    
    first = *stack;
    last = *stack;
    
    while (last->next)
        last = last->next;

    *stack = first->next;
    (*stack)->prev = NULL;
    first->next = NULL;

    last->next = first;
    first->prev = last;
}

void	ra(t_stack **a, bool checker)
{
    rotate_node(a); 
	if (!checker)
		write(1, "ra\n", 3);
}
void	rb(t_stack **b, bool checker)
{
    rotate_node(b); 
	if (!checker)
		write(1, "rb\n", 3);
}
void    rr(t_stack **a, t_stack **b, bool checker)
{
    rotate_node(a);
	rotate_node(b);
	if (!checker)
		write(1, "rr\n", 3);
} 