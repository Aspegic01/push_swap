/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:52:32 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/12 21:44:14 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	void	ft_help(char *line, t_lst **a, t_lst **b)
{
	stackclear(a);
	stackclear(b);
	free(line);
	ft_putstr_fd("Error\n", STDERR_FILENO);
}

static	void	execute(char *line, t_lst **a, t_lst **b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		do_pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		do_pb(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		do_ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		do_rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		do_rr(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		do_sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		do_sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		do_ss(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		do_rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		do_rrr(a, b);
	else
		ft_help(line, a, b);
}

static	void	get_input(t_lst **a_stack, t_lst **b_stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute(line, a_stack, b_stack);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_lst	*a_stack;
	t_lst	*b_stack;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	a_stack = NULL;
	b_stack = NULL;
	if (initstack(ac, av, &a_stack) == 0)
		return (stackclear(&a_stack), ft_putstr_fd("Error\n", STDERR_FILENO));
	else if (check_dup(a_stack) == -1)
		return (stackclear(&a_stack), ft_putstr_fd("Error\n", STDERR_FILENO));
	else
	{
		get_input(&a_stack, &b_stack);
		if (is_sorted(&a_stack) == 1)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO", 1);
	}
	stackclear(&a_stack);
	stackclear(&b_stack);
}
