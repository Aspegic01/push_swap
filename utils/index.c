/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:10:00 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/08 23:10:16 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_lst	*get_min(t_lst **stack)
{
	t_lst	*lst;
	t_lst	*lst_min;
	int		min;

	if (!(*stack))
		return (NULL);
	min = 0;
	lst_min = NULL;
	lst = *stack;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || lst->content < lst_min->content))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	ft_index(t_lst **stack)
{
	t_lst	*lst;
	int		index;

	index = 0;
	lst = get_min(stack);
	while (lst)
	{
		lst->index = index++;
		lst = get_min(stack);
	}
}
