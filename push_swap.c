/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmentor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:40:24 by tmentor           #+#    #+#             */
/*   Updated: 2019/08/20 16:12:42 by tmentor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	s(int *a, int *b, char *str);
int		p(int *a, int *b, char *str, int *n);
void	rr(int *a, int *b, char *str, int *n);
void	r(int *a, int *b, char *str, int *n);
int		error(int ac, char **av);
void	place(int *n, int ac, int *list, char **av);

void	push_swap(int *a, int *b, int *n)
{

}

int		main(int ac, char **av)
{
	int		list[ac - 1];
	int		b[ac - 1];
	int		n[2];

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
