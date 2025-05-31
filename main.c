/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:49:32 by racabrer          #+#    #+#             */
/*   Updated: 2025/05/31 21:20:44 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (argc < 2)
    {
        printf("Uso: %s num1 num2 ...\n", argv[0]);
        return 1;
    }

    // 🔹 Inicializa `stack_a` con los valores de entrada
    ft_initstack(argc - 1, argv + 1, &stack_a);

    // Comprueba si la lista ya está en orden
    if (is_sorted(stack_a))
    {
        printf("La lista ya está ordenada.\n");
        free_stack(&stack_a);
        return 0;
    }

    // 🔹 Muestra el estado inicial de `stack_a`
    printf("Stack A inicial:\n");
    print_stack(stack_a);

    // 🔹 Aplicar el algoritmo adecuado según el número de elementos en la pila
    int size = stack_size(stack_a);

    if (size == 2)
    {
        printf("\nOrdenando 2 elementos...\n");
        sort_two(&stack_a);
    }
    else if (size == 3)
    {
        printf("\nOrdenando 3 elementos...\n");
        sort_three(&stack_a);
    }

    // 🔹 Mostrar resultado final
    printf("\nStack A después de la ordenación:\n");
    print_stack(stack_a);

    // 🔹 Limpia la memoria usada
    printf("\nLiberando memoria...\n");
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}

