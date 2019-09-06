/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/06 17:20:33 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subfun/push.h"
#include <fcntl.h>

static void	checker(int *a, int x, int n)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		while (i < n)
		{
			if (a[i] < a[i + 1])
				i++;
			else
			{
				ft_putendl("KO");
				exit(0);
			}
		}
		if (i == n)
			ft_putendl("OK");
	}
	else
		ft_putendl("KO");
}

static void	sort(char *line, int *list, int *b, int *n)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb")
			|| ft_strequ(line, "ss") || ft_strequ(line, "pa")
			|| ft_strequ(line, "pb") || ft_strequ(line, "ra")
			|| ft_strequ(line, "rb") || ft_strequ(line, "rr")
			|| ft_strequ(line, "rra") || ft_strequ(line, "rrb")
			|| ft_strequ(line, "rrr"))
	{
		if (line[0] == 's')
			s(list, b, line, n);
		else if (line[0] == 'p')
			n[0] = p(list, b, line, n);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] != '\0')
			rr(list, b, line, n);
		else
			r(list, b, line, n);
		free(line);
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}

static void	com(int *a, int *b, int *n)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
		sort(line, a, b, n);
	checker(a, n[0], n[1] - 1);
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
	com(a, b, n);
}

int			main(int ac, char **av)
{
	int	i;
	int n[2];

	if (ac > 1)
	{
		if (ac < 3 && ft_strequ(av[1], ""))
			exit(0);
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
		n[0] = 0;
		if (n[1] == 0)
			exit(0);
		list(ac, av, n);
	}
}
