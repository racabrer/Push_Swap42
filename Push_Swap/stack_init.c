/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:12:57 by racabrer          #+#    #+#             */
/*   Updated: 2025/05/31 19:05:01 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
	
}
int is_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return(1);
		stack = stack->next;
	}
	return (0);
}

long ft_atol_ps(const char *str)
{
	long	result;
	int		i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!ft_isdigit(str[i]))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	while (ft_isdigit(str[i]))
		result = (str[i++] - '0') + (result * 10);
	if (!ft_isdigit(str[i]) && str[i])
		ft_putstr_fd("Error\n", STDERR_FILENO);
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (result);
}

int stack_size(t_stack *stack)
{
    int count = 0;

    while (stack)
    {
        count++;
        stack = stack->next;
    }

    return count;
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}


int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (argc < 2)
    {
        printf("Uso: %s num1 num2 ...\n", argv[0]);
        return (1);
    }

    // 🔹 Inicializa `stack_a` con los valores de entrada
    ft_initstack(argc - 1, argv + 1, &stack_a);

    // 🔹 Muestra el estado inicial de `stack_a`
    printf("Stack A inicial:\n");
    print_stack(stack_a);

    // 🔹 Aplica operaciones básicas
    printf("\nAplicando 'sa' (swap en A)...\n");
    sa(&stack_a, false);
    print_stack(stack_a);

    printf("\nAplicando 'pb' (push de A a B)...\n");
    pb(&stack_a, &stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    printf("\nAplicando 'pa' (push de B a A)...\n");
    pa(&stack_a, &stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    printf("\nAplicando 'rra' (reverse rotate en A)...\n");
    rra(&stack_a, false);
    print_stack(stack_a);

    printf("\nAplicando 'rrb' (reverse rotate en B)...\n");
    rrb(&stack_b, false);
    print_stack(stack_b);

    printf("\nAplicando 'rrr' (reverse rotate en A y B)...\n");
    rrr(&stack_a, &stack_b, false);
    print_stack(stack_a);
    print_stack(stack_b);

    // 🔹 Limpia la memoria usada
    printf("\nLiberando memoria...\n");
    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}





