/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:55:11 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/09 20:01:34 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Stack init
int					is_valid_number(const char *str);
int					is_duplicate(t_stack *stack, int num);
long				str_to_long(const char *str);

// Listas
t_stack				*ft_stacknew(int content, int index);
void				add_node_back(t_stack **stack, t_stack *new_node);
void				parse_args(char **spl_arr, t_stack **stack_a, int *index);
void				ft_initstack(int argc, char **argv, t_stack **stack_a);

// Swap
void				swap_node(t_stack **stack);
void				sa(t_stack **a, bool checker);
void				sb(t_stack **b, bool checker);
void				ss(t_stack **a, t_stack **b, bool checker);

// Push
void				push(t_stack **dest, t_stack **src);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

// Rotate
void				rotate_node(t_stack **stack);
void				ra(t_stack **a, bool checker);
void				rb(t_stack **b, bool checker);
void				rr(t_stack **a, t_stack **b, bool checker);

// Reverse Rotate
void				reverse_rotate_node(t_stack **stack);
void				rra(t_stack **a, bool checker);
void				rrb(t_stack **b, bool checker);
void				rrr(t_stack **a, t_stack **b, bool checker);

void				free_stack(t_stack **stack);
void				print_stack(t_stack *stack);

// Errors
int					is_sorted(t_stack *stack);

// Little numbers
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);

// Stack Utils
int					stack_size(t_stack *stack);
void				push_smallest_to_b(t_stack **a, t_stack **b);
t_stack				*find_smallest(t_stack *stack);
int					get_k_size(int stack_size);
void				ft_free_split(char **arr);

// Indexes
void				initialize_indexes(t_stack **stack);
t_stack				*find_smallest_unindexed(t_stack *stack);
void				assign_indexes(t_stack **stack);

// K_sort
int					get_position(t_stack *a, t_stack *smallest);
t_stack				*find_max(t_stack *stack);
void				push_back_from_b(t_stack **a, t_stack **b);
void				push_chunk_to_b(t_stack **a, t_stack **b,
						int *current_index, int k);
void				k_sort(t_stack **a, t_stack **b);

// Main
void				exit_if_sorted(t_stack **a);
void				choose_sorting(t_stack **a, t_stack **b);
int					main(int argc, char **argv);

#endif // PUSH_SWAP_H