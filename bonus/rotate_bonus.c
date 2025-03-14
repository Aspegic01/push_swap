/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:38:53 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 14:39:35 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_lst **stack)
{
	t_lst	*lst;

	if (!(*stack) || !(*stack)->next)
		return ;
	lst = lst_last(*stack);
	lst->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lst->next->prev = lst;
	lst->next->next = NULL;
}

void	do_ra(t_lst **stack)
{
	rotate(stack);
}

void	do_rb(t_lst **stack)
{
	rotate(stack);
}

void	do_rr(t_lst **a_stack, t_lst **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
}
