/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:42:33 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/04 15:16:48 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	lolo(int *a, int n, int med, int *x)
{
	while (x[1] - x[0] != 1 && x[1] - x[0] != 0)
	{
		if (x[1] - x[0] != 1)
		{
			med = med + (x[1] - x[0]);
		}
		x[2] = 0;
		x[0] = 0;
		x[1] = 0;
		while (x[2] < n)
		{
			if (a[x[2]] < med)
				x[0]++;
			else
				x[1]++;
			x[2]++;
		}
	}
	return (med);
}

static void	lole(int *a, int *b, int *n, int i)
{
	if (i < (n[1] - n[0]) / 2)
	{
		while (i != 0)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
			i--;
		}
	}
	else
	{
		while (i != (n[1] - n[0]))
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
			i++;
		}
		i = 0;
	}
}

static void	fstep(int *a, int *b, int *n)
{
	p(a, b, "pa", n);
	ft_putendl("pa");
}

int			med(int *a, int n)
{
	int med;
	int	x[3];

	x[2] = 0;
	med = 0;
	x[0] = 0;
	x[1] = 0;
	while (x[2] < n)
	{
		med = med + a[x[2]];
		x[2]++;
	}
	med = med / x[2];
	x[2] = 0;
	while (x[2] < n)
	{
		if (a[x[2]] < med)
			x[0]++;
		else
			x[1]++;
		x[2]++;
	}
	med = lolo(a, n, med, x);
	return (med);
}

void		bsort(int *a, int *b, int *n)
{
	int	m;
	int	i;

	if (!checka(a, n[1]))
	{
		m = med(a, n[1]);
		i = 0;
		while (i < n[1] - n[0])
		{
			if (a[0] < m)
			{
				p(a, b, "pb", n);
				ft_putendl("pb");
				i = 0;
			}
			if (a[i] < m)
				lole(a, b, n, i);
			i++;
		}
		asort(a, b, n);
		revsort(a, b, n);
		while (n[0] != 0)
			fstep(a, b, n);
	}
}
