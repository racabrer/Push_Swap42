/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:49:32 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/02 17:55:32 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (argc < 2)
    {
        printf("Uso: %s num1 num2 ...\n", argv[0]);
        return (1);
    }

    // Inicializar pila con los valores de entrada
    ft_initstack(argc - 1, argv + 1, &stack_a);
    assign_indexes(&stack_a);

    // Verificar estado de la lista
    int sorted_status = is_sorted(stack_a);
    if (sorted_status == -2)  // Solo hay un número
    {
        printf("Solo hay un número en la lista.\n");
        free_stack(&stack_a);
        return (0);
    }
    else if (sorted_status == 1)  // Ya está ordenada
    {
        printf("La lista ya está ordenada.\n");
        free_stack(&stack_a);
        return (0);
    }

    printf("Stack A inicial:\n");
    print_stack(stack_a);

    // Aplicar el algoritmo de ordenación correcto
    int size = stack_size(stack_a);
    if (size == 2)
        sort_two(&stack_a);
    else if (size == 3)
        sort_three(&stack_a);
    else if (size == 4)
        sort_four(&stack_a, &stack_b);
    else if (size == 5)
        sort_five(&stack_a, &stack_b);
    else
        printf("No hay algoritmo para ordenar %d números.\n", size);

    printf("\nStack A después de la ordenación:\n");
    print_stack(stack_a);

    // Liberación de memoria
    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}




