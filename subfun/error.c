/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:24:12 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/06 13:00:10 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	error(int ac, int *a)
{
	int		n;
	int		i;

	n = 0;
	if (ac > 1)
	{
		while (++n <= ac)
		{
			i = 0;
			while (i < n)
			{
				if (a[i] == a[n])
				{
					ft_putendl("Error");
					exit(0);
				}
				i++;
			}
		}
	}
}

void	place(int *x, int *a, char **av)
{
	if ((a[x[1] - 1] = ft_atoi(av[x[2]]))
			|| ft_strequ(av[x[2]], "0"))
	{
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}

void	placeb(int *n, int *a, char **av)
{
	int	i;

	i = 0;
	while (i < n[0])
	{
		if ((a[n[2]] = ft_atoi(av[i]))
				|| ft_strequ(av[i], "0"))
		{
			n[2]++;
			i++;
		}
		else
		{
			ft_putendl("Error");
			exit(0);
		}
	}
}

void	erplb(int *a, int *x, char **tmp)
{
	placeb(x, a, tmp);
	error(x[1], a);
}

void	erpl(int *a, int *x, char **tmp)
{
	place(x, a, tmp);
	error(x[1], a);
}
