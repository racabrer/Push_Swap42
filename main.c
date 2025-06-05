/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:49:32 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/05 16:42:00 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
    {
        printf("Uso: %s num1 num2 ...\n", argv[0]);
        return (1);
    }

    ft_initstack(argc - 1, argv + 1, &a);
    assign_indexes(&a);

    printf("Stack A inicial:\n");
    print_stack(a);

    int k = get_k_size(stack_size(a));
    printf("K size calculado: %d\n", k);

    printf("\nBuscando el nodo más pequeño y pasándolo a B...\n");
    push_smallest_to_b(&a, &b);

    printf("Stack A:\n");
    print_stack(a);
    printf("Stack B:\n");
    print_stack(b);

    t_stack *smallest = find_smallest(a);
    if (smallest)
        printf("El más pequeño ahora en A es: %d\n", smallest->content);

    int pos = get_position(a, smallest);
    printf("Posición del más pequeño en A: %d\n", pos);

    free_stack(&a);
    free_stack(&b);
    return 0;
}





