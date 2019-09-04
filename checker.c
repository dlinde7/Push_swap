/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/04 16:22:45 by dlinde           ###   ########.fr       */
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

static void	erpl(int ac, char **av, int *list, int *n)
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
	n[0] = 0;
	n[1] = n[2];
}

int			main(int ac, char **av)
{
	int		list[ac - 1];
	int		b[ac - 1];
	int		n[3];
	char	*line;
	char	**tmp;

	n[0] = 0;
	n[2] = 0;
	if (ac > 1 && ac < 3)
	{
		n[2] = ft_wordcount(av[1], ' ');
		tmp = ft_strsplit(av[1], ' ');
		erplb(n[2], tmp, list, n);
		while (get_next_line(0, &line) == 1)
			sort(line, list, b, n);
		checker(list, n[0], n[2]);
	}
	if (ac > 2)
	{
		erpl(ac, av, list, n);
		while (get_next_line(0, &line) == 1)
			sort(line, list, b, n);
		checker(list, n[0], ac - 2);
	}
}
