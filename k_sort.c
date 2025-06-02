/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:27:50 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/02 20:18:17 by racabrer         ###   ########.fr       */
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

//hay que revisar esto
  void push_chunks_to_b(t_stack **a, t_stack **b, int k)
{
	int size;
	int chunk_size;
	int current_limit; //establece el límite actual de índice para el primer fragmento

	size = stack_size(*a);
	chunk_size = size / k;
	current_limit = chunk_size;
	while (*a)
	{
		if((*a)->index < current_limit)
		{
			pb(a, b);
			if ((*b)->index < current_limit - chunk_size / 2)
				rb(b, true);
			else if (stack_size(*a) > 1 && (*a)->index >= current_limit + chunk_size)
				rra(a, true);
			else
				ra(a, true);
		}
		if (stack_size(*b) == current_limit || stack_size(*b) >= chunk_size )
			current_limit += (chunk_size / 2);
		if (*b && stack_size(*b) > 1 && (*b)->index > (*b)->next->index)
			sb(b, true);
	}
}


 

