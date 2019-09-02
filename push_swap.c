/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmentor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:40:24 by tmentor           #+#    #+#             */
/*   Updated: 2019/09/02 15:49:34 by dlinde           ###   ########.fr       */
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

int		checkb(int *b, int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (b[i] < b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		med(int *a, int n)
{
	int med;
	int	x[2];
	int i;

	i = 0;
	med = 0;
	x[0] = 0;
	x[1] = 0;
	while (i < n)
	{
		med = med + a[i];
		i++;
	}
	med = med / i; 
	i = 0;
	while (i < n)
	{
		if (a[i] < med)
			x[0]++;
		else
			x[1]++;
		i++;
	}
	while (x[1] - x[0] != 1 && x[1] - x[0] != 0)
	{
		if (x[1] - x[0] != 1)
		{
			if (n != 6)
				med = med + (x[1] - x[0]);
			else
				med = med + (x[1] - x[0]) - 1;
		}
		i = 0;
		x[0] = 0;
		x[1] = 0;
		while (i < n)
		{
			if (a[i] < med)
				x[0]++;
			else
				x[1]++;
			i++;
		}
	}
	return (med);
}

void	asort(int *a, int *b, int *n)
{
	while (!checka(a, n[1] - n[0]))
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

void	revsort(int *a, int *b, int *n)
{
	while (!checkb(b, n[0]))
	{
		if (b[1] < b[0] && b[2] < b[0] && b[1] > b[2])
		{
			s(a, b, "sb", n);
			ft_putendl("sb");
			r(a, b, "rb", n);
			ft_putendl("rb");
		}
		else if (b[1] > b[0] && b[2] < b[0] && b[1] > b[2])
		{
			s(a, b, "sb", n);
			ft_putendl("sb");
		}
		else if ((b[0] < b[1] && b[1] < b[2]) || (b[1] > b[0] && b[1] > b[2] && b[2] > b[0]))
		{
			r(a, b, "rb", n);
			ft_putendl("rb");
		}
		else
		{
			rr(a, b, "rrb", n);
			ft_putendl("rrb");
		}
	}
}

void	bsort(int *a, int *b, int *n)
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
			i++;
		}
		asort(a, b, n);
		revsort(a, b, n);
		while (n[0] != 0)
		{
			p(a, b, "pa", n);
			ft_putendl("pa");
		}
	}
}

void	sorta(int *a, int *b, int *n)
{
	int c[2];
	int d;
	int z[2];
	int	x;
	int i;

	i = 0;
	c[0] = a[0];
	c[1] = 0;
	x = 0;
	z[0] = 0;
	while (i < n[1] - n[0])
	{
		if (a[i] < c[0])
		{
			c[0] = a[i];
			x = i;
		}
		if (a[i] > c[1])
			c[1] = a[i];
		i++;
	}
	ft_putnbr(c[1]);
	ft_putchar('\n');
	while (!checka(a, n[1] - n[0]))
	{
		i = 0;
		d = c[1];
		while (i < n[1] - n[0])
		{
			if (a[i] > c[0] && a[i] < d)
			{
				d = a[i];
				z[0] = i;
			}
			if (a[i] == c[1])
				z[1] = i;
			i++;
		}
		if (d == c[1])
			z[0] = z[1];
		if (z[0] < x)
			x = (i - x) + z[0];
		else
			x = z[0] - x;
		if (x != 1)
		{
			if (z[0] < (n[1] - n[0]) / 2)
			{
				while (z[0] != 1)
				{
					r(a, b, "ra", n);
					ft_putendl("ra");
					z[0]--;
				}
			}
			else
			{
				while (z[0] != i + 1)
				{
					rr(a, b, "rra", n);
					ft_putendl("rra");
					z[0]++;
				}
			}
			while (x != 1)
			{
				s(a, b, "sa", n);
				ft_putendl("sa");
				rr(a, b, "rra", n);
				ft_putendl("rra");
				x--;
			}
			z[0] = 0;
		}
		else
			x = z[0];
		if (d == c[1])
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
		}
		c[0] = d;
	}
	i = 0;
	while (i < n[1] - n[0])
	{
		ft_putnbr(a[i]);
		ft_putchar(' ');
		i++;
	}
}

void	sort(int *a, int *b, int *n)
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
			i++;
		}
		sorta(a, b, n);
		/*while (n[0] != 0)
		{
			p(a, b, "pa", n);
			ft_putendl("pa");
		}*/
	}
}

void	push_swap(int *a, int *b, int *n)
{
	if (n[1] > 6)
		sort(a, b, n);
	else if (n[1] > 3 && n[1] < 7)
		bsort(a, b, n);
	else
		asort(a, b, n);
}

int		main(int ac, char **av)
{
	int		list[ac - 1];
	int		b[ac - 1];
	int		n[2];
	int		i;

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
		push_swap(list, b, n);
	}
}
