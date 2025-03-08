/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrirh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:00:18 by mlabrirh          #+#    #+#             */
/*   Updated: 2025/03/02 15:31:56 by mlabrirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

void	alpha_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			if (ft_isalpha(av[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

int	check_error(char **av)
{
	int	i;
	int	j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			if (sign(av[i][j]))
			{
				j++;
				if (!ft_isdigit(av[i][j]))
					return false;
			}
			else if (ft_isdigit(av[i][j]))
			{
				j++;
				if (av[i][j] == '\0')
					break ;
				if (!ft_isdigit(av[i][j]) && !space(av[i][j]))
					return false;
			}
			j++;
		}
		i++;
	}
	return true;
}

bool	ft_syntax_check(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (true);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (true);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (true);
	}
	return (false);
}

bool	check_all_av(char **av)
{
	int	i;

	i = 1;
	while(av[i] != NULL)
	{
		if (ft_syntax_check(av[i]))
			return true;
		i++;
	}
	return false;
}

int check_args(char **av)
{
	alpha_check(av);
	if (!check_error(av))
		return false;
	else if (!check_all_av(av))
		return false;
	return true;
}
