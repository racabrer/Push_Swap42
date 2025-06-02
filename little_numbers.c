/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:08:25 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/02 17:42:37 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack **a)
{
    if (*a && (*a)->next && !is_sorted(*a)) // Solo hacemos algo si hay al menos dos nodos y no está ordenada
    {
        if ((*a)->content > (*a)->next->content)
            sa(a, false);
    }
}


void sort_three(t_stack **a) // Usamos doble puntero
{
      /*
    1. a->value
    2. a->next->value
    3. a->next->next->value
    */
    if (is_sorted(*a)) // Comprobamos si la pila ya está ordenada
        return;

    // Caso 3 2 1
    if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content) 
    {
        sa(a, false); // intercambiamos los dos primeros nodos
        rra(a, false); // rotación inversa
    }
    // Caso 3 1 2
    else if ((*a)->content > (*a)->next->next->content && (*a)->next->next->content > (*a)->next->content) 
        ra(a, false); // rotación hacia adelante
    // Caso 2 3 1
    else if ((*a)->next->content > (*a)->content && (*a)->content > (*a)->next->next->content) 
        rra(a, false); // rotación inversa
    // Caso 2 1 3
    else if ((*a)->content > (*a)->next->content && (*a)->next->next->content > (*a)->content) 
        sa(a, false); // intercambio de los dos primeros nodos
    // Caso 1 3 2
    else if ((*a)->next->content > (*a)->next->next->content && (*a)->next->next->content > (*a)->content) 
    {
        sa(a, false);
        ra(a, false);
    }
}

void sort_four(t_stack **a, t_stack **b)
{
    int size;

    if (is_sorted(*a))
        return;

    size = stack_size(*a);
    if (size == 4)
        push_smallest_to_b(a, b);

    sort_three(a);

    if (stack_size(*b) == 2 && (*b)->content > (*b)->next->content)
        sb(b, false); 

    while (stack_size(*b) > 0)
        pa(a, b); 
}
void	sort_five(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return;
	while (stack_size(*a) > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	if (stack_size(*b) == 2 && (*b)->index < (*b)->next->index)
		sb(b, false);
	while (*b)
		pa(a, b);
}


