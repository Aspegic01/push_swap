/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:32:21 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 14:36:36 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./my_printf/ft_printf.h"
#include <limits.h>

typedef struct s_lst
{
	int				content;
	int				index;
	int 			move;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

void	ft_error(void);
void	creat_stack(t_lst **a, char **av);
int check_args(char **av);
bool stack_sort(t_lst *stack);
int	lst_size(t_lst *stack);
void	sa(t_lst **a);
bool	ft_syntax_check(char *argv);
static void	ft_free(char **str);
static int	initstack(int ac, char **av, t_lst **a_stack);
int	is_sorted(t_lst **stack);
void	radix_sort(t_lst **stack_a, t_lst **stack_b);
int	ft_checksorted(t_lst *stack_a);
void	lst_addfront(t_lst **stack, t_lst *news);
void	lst_addback(t_lst **stack, t_lst *news);
t_lst	*lst_new(int content);
t_lst *lst_last(t_lst *stack);
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
