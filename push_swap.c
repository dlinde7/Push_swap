/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:22:56 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/06 17:21:58 by dlinde           ###   ########.fr       */
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

static void	list(int ac, char **av, int *n)
{
	int		x[3];
	int		i[3];
	int		a[n[1]];
	int		b[n[1]];

	i[1] = 0;
	i[0] = 1;
	x[1] = 0;
	while (i[0] < ac)
	{
		x[0] = ft_wordcount(av[i[0]], ' ');
		x[1] += x[0];
		if (x[0] > 1)
		{
			x[2] = x[1] - x[0];
			totmp(av[i[0]], a, x);
		}
		else if (x[0] != 0)
		{
			x[2] = i[0];
			erpl(a, x, av);
		}
		i[0]++;
	}
	push_swap(a, b, n);
}

int			main(int ac, char **av)
{
	int	i;
	int n[2];

	if (ac > 1)
	{
		n[1] = 0;
		i = 1;
		while (i < ac)
		{
			n[0] = ft_wordcount(av[i], ' ');
			if (n[0] == 0 && !ft_strequ(av[i], ""))
			{
				ft_putendl("Error");
				exit(0);
			}
			n[1] += n[0];
			i++;
		}
		if (n[1] == 0)
			exit(0);
		n[0] = 0;
		list(ac, av, n);
	}
}
