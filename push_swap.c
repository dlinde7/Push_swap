/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:22:56 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/04 15:27:12 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subfun/push.h"

static void	push_swap(int *a, int *b, int *n)
{
	if (n[1] > 6)
		finalsort(a, b, n);
	else if (n[1] > 3 && n[1] < 7)
		bsort(a, b, n);
	else
		asort(a, b, n);
}

static void	erpl(int ac, char **av, int *list, int *n)
{
	if (error(ac, av))
		place(n, ac, list, av);
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}

static void	erplb(int i, char **tmp, int *list, int *n)
{
	if (error(i, tmp))
	{
		placeb(n, i, list, tmp);
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}

int			main(int ac, char **av)
{
	int		list[ac - 1];
	int		b[ac - 1];
	int		n[2];
	int		i;
	char	**tmp;

	i = 0;
	n[0] = 0;
	if (ac > 1 && ac < 3)
	{
		i = ft_wordcount(av[1], ' ');
		tmp = ft_strsplit(av[1], ' ');
		erplb(i, tmp, list, n);
		n[0] = 0;
		n[1] = i;
		push_swap(list, b, n);
	}
	else if (ac > 2)
	{
		erpl(ac, av, list, n);
		n[0] = 0;
		n[1] = ac - 1;
		push_swap(list, b, n);
	}
}
