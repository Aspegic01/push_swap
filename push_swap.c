/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:20:59 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/02 17:40:20 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	push_swap(char **av, int size)
{
	check_args(av);
}

int	ft_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL && lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int main(int ac, char **av)
{
	char	**split;
	t_stack *a;
	t_stack	*b;
	int i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return 1;
	if (ac == 2)
	{
		split = ft_split(av[1], 32);
		creat_stack(&a, split);
		if (!stack_sort(a))
		{
			if (ft_size(a) == 2)
				sa(&a);
		}
	}

	else if (ac > 2)
	{
		creat_stack(&a, av + 1);
		i = ft_size(a);
		printf("%d", i);
		if (!stack_sort(a))
		{
			if (ft_size(a) == 2)
				sa(&a);
			if (ft_size(a) == 3)
				sa(&a);
		}
	}

}
