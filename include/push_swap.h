/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:32:21 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/10 14:44:27 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct s_range
{
	int	*sorted_array;
	int	offset;
	int	size;
	int	start;
	int	end;
}				t_range;

void	sort_three(t_lst **a);
bool	stack_sort(t_lst *stack);
int		lst_size(t_lst *stack);
void	ft_index(t_lst **stack);
int		is_sorted(t_lst **stack);
void	push_elements_to_a(t_lst **a, t_lst **b);
void	push_element_to_b(t_lst **a, t_lst **b, t_range *range);
void	next_chunk(t_range *range);
void	large_sort(t_lst **a, t_lst **b, int size);
int		*stack_to_array(t_lst *stack, int size);
void	sorted_array(int *array, int size);
void	lst_addfront(t_lst **stack, t_lst *news);
void	lst_addback(t_lst **stack, t_lst *news);
t_lst	*lst_new(int content);
t_lst	*lst_last(t_lst *stack);
//swap function
void	do_sa(t_lst **stack);
void	do_sb(t_lst **stack);
void	do_ss(t_lst **a_stack, t_lst **b_stack);
//reverse function
void	do_rra(t_lst **stack);
void	do_rrb(t_lst **stack);
void	do_rrr(t_lst **a_stack, t_lst **b_stack);
//rotate function
void	do_ra(t_lst **stack);
void	do_rb(t_lst **stack);
void	do_rr(t_lst **a_stack, t_lst **b_stack);
//push
void	do_pa(t_lst **a_stack, t_lst **b_stack);
void	do_pb(t_lst **a_stack, t_lst **b_stack);
#endif
