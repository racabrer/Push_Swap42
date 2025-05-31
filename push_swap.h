/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:55:11 by racabrer          #+#    #+#             */
/*   Updated: 2025/05/31 21:24:34 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#ifndef S_STACK_H
# define S_STACK_H

# include "libft/libft.h" 


typedef struct t_stack
{
	int 	nbr;
	int 	content;
	int		index;
	struct  t_stack *next;
	struct	t_stack *prev;
} t_stack;


//Stack init
int is_valid_number(const char *str);
int is_duplicate(t_stack *stack, int num);
long ft_atol_ps(const char *str);

// Listas
t_stack *ft_stacknew(int content, int index); 
void add_node_back(t_stack **stack, t_stack *new_node);
void print_stack(t_stack *stack);
void ft_initstack(int argc, char **argv, t_stack **stack_a);
void ft_free_split(char **arr);

//Swap
void 	swap_node(t_stack **stack);
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

//Push
void push(t_stack **dest, t_stack **src);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

//Rotate
void	rotate_node(t_stack **stack);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void    rr(t_stack **a, t_stack **b, bool checker);

//Reverse Rotate
void 	reverse_rotate_node(t_stack **stack);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void    rrr(t_stack **a, t_stack **b, bool checker);

int 	stack_size(t_stack *stack);
void 	free_stack(t_stack **stack);
void 	print_stack(t_stack *stack);

//Errors
int		is_sorted(t_stack *stack);


//Little numbers
void sort_two(t_stack **a);
void sort_three(t_stack **a) ;

#endif  // S_STACK_H