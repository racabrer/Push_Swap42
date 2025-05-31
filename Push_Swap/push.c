/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:39:01 by racabrer          #+#    #+#             */
/*   Updated: 2025/05/29 19:14:52 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

void push(t_stack **dest, t_stack **src)
{
    t_stack *temp;

    if (!src || !*src)
        return;

    temp = *src;
    *src = (*src)->next;

    if (*src)
        (*src)->prev = NULL;

    temp->next = *dest;
    if (*dest)
        (*dest)->prev = temp;
	else
		temp->prev = NULL;
    *dest = temp;
}
void pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}