/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:37:27 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 14:38:36 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse(t_lst **stack)
{
	t_lst	*lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = lst_last(*stack);
	lst->prev->next = NULL;
	lst->prev = NULL;
	lst->next = *stack;
	(*stack)->prev = lst;
	*stack = (*stack)->prev;
}

void	do_rra(t_lst **stack)
{
	reverse(stack);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_lst **stack)
{
	reverse(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_lst **a_stack, t_lst **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_putstr_fd("rrr\n", 1);
}
