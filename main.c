/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:49:32 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/06 17:02:39 by racabrer         ###   ########.fr       */
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

    if (is_sorted(a))
    {
        printf("La lista ya está ordenada.\n");
        free_stack(&a);
        return (0);
    }

    int size = stack_size(a);
    printf("Tamaño de la pila: %d\n", size);

    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size == 4)
        sort_four(&a, &b);
    else if (size == 5)
        sort_five(&a, &b);
    else
    {
        printf("Ordenando con k_sort...\n");
        k_sort(&a, &b);
    }

    printf("\nStack A ordenado:\n");
    print_stack(a);

    // Nueva línea para imprimir la pila B después de la ordenación
    printf("\nStack B (si queda algún elemento):\n");
    print_stack(b);

    free_stack(&a);
    free_stack(&b);
    return (0);
}







