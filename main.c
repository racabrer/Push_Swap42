/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:49:32 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/06 19:07:35 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return (1);
    ft_initstack(argc - 1, argv + 1, &a);
    assign_indexes(&a);
    if (is_sorted(a))
    {
        //printf("La lista ya está ordenada.\n");
        free_stack(&a);
        return (0);
    }
    int size = stack_size(a);
    //printf("Tamaño de la pila: %d\n", size);
    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size == 4)
        sort_four(&a, &b);
    else if (size == 5)
        sort_five(&a, &b);
    else
        k_sort(&a, &b);
    print_stack(a);
    free_stack(&a);
    free_stack(&b);
    return (0);
}







