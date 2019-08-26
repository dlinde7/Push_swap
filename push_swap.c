/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmentor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:40:24 by tmentor           #+#    #+#             */
/*   Updated: 2019/08/26 16:41:25 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	s(int *a, int *b, char *str, int *n);
int		p(int *a, int *b, char *str, int *n);
void	rr(int *a, int *b, char *str, int *n);
void	r(int *a, int *b, char *str, int *n);
int		error(int ac, char **av);
void	place(int *n, int ac, int *list, char **av);

int		checka(int *a, int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	asort(int *a, int *b, int *n)
{
	while (!checka(a, n[1]))
	{
		if (a[1] > a[0] && a[2] > a[0] && a[1] > a[2])
		{
			s(a, b, "sa", n);
			ft_putendl("sa");
			r(a, b, "ra", n);
			ft_putendl("ra");
		}
		else if (a[1] < a[0] && a[2] > a[0] && a[1] < a[2])
		{
			s(a, b, "sa", n);
			ft_putendl("sa");
		}
		else if ((a[0] > a[1] && a[1] > a[2]) || (a[1] < a[0] && a[1] < a[2] && a[2] < a[0]))
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
		}
		else
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
		}
	}
}

void	push_swap(int *a, int *b, int *n, char **list)
{
	/*if (n[1] > 5)
		sort;
	else if (3 < n[1] < 6)
		bsort;
	else*/
		asort(a, b, n);
}

int		main(int ac, char **av)
{
	int		list[ac - 1];
	int		b[ac - 1];
	int		n[2];
	int		i;
	char	**line;

	i = 0;
	n[0] = 0;
	if (ac != 1)
	{
		if (error(ac, av))
			place(n, ac, list, av);
		else
		{
			ft_putendl("Error");
			exit(0);
		}
		n[0] = 0;
		n[1] = ac - 1;
		push_swap(list, b, n, line);
	}
}
