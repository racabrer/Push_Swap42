/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:09:43 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/09 19:54:35 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		return ;
	}
	current = stack;
	while (current)
		current = current->next;
}

void	ft_initstack(int argc, char **argv, t_stack **stack_a)
{
	char	**spl_arr;
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (i < argc)
	{
		spl_arr = ft_split(argv[i], ' ');
		if (!spl_arr)
			exit(EXIT_FAILURE);
		parse_args(spl_arr, stack_a, &index);
		ft_free_split(spl_arr);
		i++;
	}
}

void	parse_args(char **spl_arr, t_stack **stack_a, int *index)
{
	int	j;

	j = 0;
	while (spl_arr[j])
	{
		if (!is_valid_number(spl_arr[j]) || is_duplicate(*stack_a,
				(int)str_to_long(spl_arr[j])))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		add_node_back(stack_a, ft_stacknew((int)str_to_long(spl_arr[j]),
				*index));
		(*index)++;
		j++;
	}
}
