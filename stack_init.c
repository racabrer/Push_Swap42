/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:12:57 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/02 16:41:48 by racabrer         ###   ########.fr       */
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
/*
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
*/


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






