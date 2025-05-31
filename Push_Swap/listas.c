/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:09:43 by racabrer          #+#    #+#             */
/*   Updated: 2025/05/31 19:02:20 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *ft_stacknew(int content, int index)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}


// t_stack *ft_stacknew(int content, int index)
// {
// 	t_stack *new;

// 	new = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->index = index;
// 	new->next = NULL;
// 	return (new);
	
// }

void add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack *last_node;

	if (!new_node)
		return;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
	
}

void print_stack(t_stack *stack)
{
	t_stack *last;

	if (!stack)
	{
		printf("(vacio)\n");
		printf("Backward:\n(vacio)\n");
		return;
	}
	t_stack * current = stack;
	while (current)
	{
		printf("Nodo: content = %d, index = %d\n", current->content, current->index);
		if(!current->next)
			last = current;
		current = current->next;
	}
	printf("Backward:\n");
	current = last;
	while (current)
	{
		printf("Nodo: conten = %d, index = %d\n", current->content, current->index);
		current = current->prev;
	}
}

//ORIGINAL
// void print_stack(t_stack *stack)
// {
// 	if (!stack)
//     {
//         printf("(vacío)\n");
//         return;
//     }
// 	while(stack)
// 	{
// 		printf("Nodo: content = %d, index = %d\n", stack->content, stack->index);
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }

void ft_initstack(int argc, char **argv, t_stack **stack_a)
{
    char **spl_arr;
    int i;
    int j;
    long num;
    int index;

    i = 0;
    index = 0;
    while (i < argc)
    {
        spl_arr = ft_split(argv[i], ' ');
        if (!spl_arr)
            exit(EXIT_FAILURE);
        j = 0;
        while (spl_arr[j])
        {
            if (!is_valid_number(spl_arr[j]) || is_duplicate(*stack_a, (int)ft_atol_ps(spl_arr[j])))
                exit(write(2, "Error\n", 6));
            add_node_back(stack_a, ft_stacknew((int)ft_atol_ps(spl_arr[j]), index));
            index = index + 1;
            j = j + 1;
        }
        ft_free_split(spl_arr);
        i = i + 1;
    }
}

void ft_free_split(char **arr)
{
    int i = 0;

    if (!arr)
        return;

    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
