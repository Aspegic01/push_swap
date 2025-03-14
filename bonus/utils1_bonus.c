/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:33:28 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/13 14:33:37 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	lst_addfront(t_lst **stack, t_lst *news)
{
	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	(*stack)->prev = news;
	news->next = *stack;
	*stack = news;
	news->prev = NULL;
}

void	lst_addback(t_lst **stack, t_lst *news)
{
	t_lst	*tmp;

	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = news;
	news->prev = tmp;
}

int	lst_size(t_lst *stack)
{
	int		i;
	t_lst	*lst;

	lst = stack;
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lst	*lst_new(int content)
{
	t_lst	*stack;

	stack = malloc(sizeof(t_lst));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_lst	*lst_last(t_lst *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
