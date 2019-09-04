/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:39:21 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/04 16:25:01 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	torr(int *a, int *b, int *n, char *s)
{
	if (ft_strequ(s, "rra"))
	{
		rr(a, b, "rra", n);
		ft_putendl("rra");
	}
	else if (ft_strequ(s, "rrb"))
	{
		rr(a, b, "rrb", n);
		ft_putendl("rrb");
	}
}

void		asort(int *a, int *b, int *n)
{
	while (!checka(a, n[1] - n[0]))
	{
		if (a[1] > a[0] && a[2] > a[0] && a[1] > a[2] && n[1] - n[0] == 3)
		{
			s(a, b, "sa", n);
			ft_putendl("sa");
			r(a, b, "ra", n);
			ft_putendl("ra");
		}
		else if (a[1] < a[0] && a[2] > a[0] && a[1] < a[2] && n[1] - n[0] == 3)
		{
			s(a, b, "sa", n);
			ft_putendl("sa");
		}
		else if (((a[0] > a[1] && a[1] > a[2])
				|| (a[1] < a[0] && a[1] < a[2] && a[2] < a[0]))
				&& n[1] - n[0] == 3)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
		}
		else
			torr(a, b, n, "rra");
	}
}

void		revsort(int *a, int *b, int *n)
{
	while (!checkb(b, n[0]))
	{
		if (b[1] > b[0] && b[2] > b[0] && b[1] < b[2] && n[0] == 3)
		{
			s(a, b, "sb", n);
			ft_putendl("sb");
			rr(a, b, "rrb", n);
			ft_putendl("rrb");
		}
		else if (b[1] > b[0] && b[2] < b[0] && b[1] > b[2] && n[0] == 3)
		{
			s(a, b, "sb", n);
			ft_putendl("sb");
		}
		else if (b[0] < b[1] && b[1] > b[2] && b[0] < b[2] & n[0] == 3)
		{
			r(a, b, "rb", n);
			ft_putendl("rb");
		}
		else
			torr(a, b, n, "rrb");
	}
}
