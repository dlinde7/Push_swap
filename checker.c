/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/08/20 14:51:54 by tmentor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>

void	s(int *a, int *b, char *str);
int		p(int *a, int *b, char *str, int *n);
void	rr(int *a, int *b, char *str, int *n);
void	r(int *a, int *b, char *str, int *n);
void	place(int *n, int ac, int *list, char **av);
int		error(int ac, char **av);

void	checker(int *a, int x, int n)
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

void	sort(char *line, int *list, int *b, int *n)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb")
			|| ft_strequ(line, "ss") || ft_strequ(line, "pa")
			|| ft_strequ(line, "pb") || ft_strequ(line, "ra")
			|| ft_strequ(line, "rb") || ft_strequ(line, "rr")
			|| ft_strequ(line, "rra") || ft_strequ(line, "rrb")
			|| ft_strequ(line, "rrr"))
	{
		if (line[0] == 's')
			s(list, b, line);
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

int		main(int ac, char **av)
{
	int		list[ac - 1];
	int		b[ac - 1];
	int		n[2];
	char	*line;

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
		while (get_next_line(0, &line) == 1)
			sort(line, list, b, n);
		checker(list, n[0], ac - 2);
	}
}
