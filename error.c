/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmentor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:50:49 by tmentor           #+#    #+#             */
/*   Updated: 2019/08/20 14:51:34 by tmentor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		error(int ac, char **av)
{
	int		n;
	int		i;

	n = 0;
	while (++n < ac)
	{
		i = 0;
		while (++i < n)
			if (ft_strequ(av[n], av[i]))
				return (0);
	}
	return (1);
}

void	place(int *n, int ac, int *list, char **av)
{
	while (n[0] <= ac - 2)
	{
		if ((list[n[0]] = ft_atoi(av[n[0] + 1]))
				|| ft_strequ(av[n[0] + 1], "0"))
			n[0]++;
		else
		{
			ft_putendl("Error");
			exit(0);
		}
	}
}