/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:52:43 by dlinde            #+#    #+#             */
/*   Updated: 2019/09/06 12:37:35 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft/libft.h"

void	s(int *a, int *b, char *str, int *n);
int		p(int *a, int *b, char *str, int *n);
void	rr(int *a, int *b, char *str, int *n);
void	r(int *a, int *b, char *str, int *n);
void	error(int ac, int *a);
void	place(int *x, int *a, char **av);
void	placeb(int *n, int *a, char **av);
void	erpl(int *a, int *x, char **tmp);
void	erplb(int *a, int *x, char **tmp);
int		checka(int *a, int n);
int		checka(int *a, int n);
int		checkb(int *b, int n);
void	finalsort(int *a, int *b, int *n);
void	sortb(int *a, int *b, int *n);
void	passb(int *a, int *b, int *n);
int		med(int *a, int n);
void	bsort(int *a, int *b, int *n);
void	asort(int *a, int *b, int *n);
void	revsort(int *a, int *b, int *n);
void	ex(int *min, int *max, int *i);
void	totmp(char *av, int *a, int *x);

#endif
