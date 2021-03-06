/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:44:40 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/06 12:37:12 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	updown(int *a, int *b, int *n, int *i)
{
	if (i[1] < i[0] / 2)
	{
		while (i[1] > 0)
		{
			r(a, b, "rb", n);
			ft_putendl("rb");
			i[1]--;
		}
	}
	else
	{
		while (i[1] < i[0])
		{
			rr(a, b, "rrb", n);
			ft_putendl("rrb");
			i[1]++;
		}
	}
}

void		sortb(int *a, int *b, int *n)
{
	p(a, b, "pb", n);
	ft_putendl("pb");
	if (n[1] - n[0] == 3)
	{
		asort(a, b, n);
	}
}

void		passb(int *a, int *b, int *n)
{
	int max;
	int i[2];

	while (n[0] > 0)
	{
		i[0] = 0;
		max = -2147483648;
		i[1] = 0;
		while (i[0] < n[0])
		{
			if (b[i[0]] > max)
			{
				max = b[i[0]];
				i[1] = i[0];
			}
			i[0]++;
		}
		updown(a, b, n, i);
		p(a, b, "pa", n);
		ft_putendl("pa");
	}
}

void		ex(int *min, int *max, int *i)
{
	if (min[1] >= max[2])
		min[1] = max[2] - 1;
	i[2] = min[1];
}

void		totmp(char *av, int *a, int *x)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(av, ' ');
	erplb(a, x, tmp);
	while (i < ft_wordcount(av, ' '))
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
