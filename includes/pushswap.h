/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:09:15 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/15 10:14:18 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_lst
{
	int				element;
	struct s_lst	*next;
}				t_lst;

void	error(void);
int		error_sign(char *s, int *i);
void	check_errors(char **av, int *i, int *j);
int		arg(char c);
void	no_args(int ac);
t_lst	*lstnew(int element);
t_lst	*lstlast(t_lst *lst);
void	find_errors(char **av, int ac);
void	display(t_lst *a, t_lst *b);
void	swap_a(t_lst **lst, int print);
void	swap_b(t_lst **lst, int print);
void	swap_a_b(t_lst **a, t_lst **b, int print);
void	rotate_a(t_lst **lst, int print);
void	rotate_b(t_lst **lst, int print);
void	rotate_a_b(t_lst **a, t_lst **b, int print);
void	push(t_lst **a, t_lst **b);
void	push_a(t_lst **a, t_lst **b, int print);
void	push_b(t_lst **b, t_lst **a, int print);
void	reverse_a(t_lst **lst, int print);
void	reverse_b(t_lst **lst, int print);
void	reverse_a_b(t_lst **a, t_lst **b, int print);
void	checker(t_lst *a, t_lst *b);
void	checkdouble(t_lst *a);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_memchr2(char *s, char c);
char	*ft_substr2(char *s, unsigned int start, size_t len);
char	*read_line(int fd, char *str, int *res);
int		get_next_line(int fd, char **line);
t_lst	*ft_lstlast(t_lst *lst);
void	inst_swap_push(char *line, t_lst **a, t_lst **b);
void	inst_rot_rev(char *line, t_lst **a, t_lst **b);
void	instructions(t_lst **a, t_lst **b);
void	lstadd_back(t_lst **alst, t_lst *new);
int		lstsize(t_lst *lst);
int		ft_findchr(char *s, char c);
int		size_int(int nb);
int		*ft_sort_int_tab(int *tab, int size);
long	ft_atol(char *s);
int		find_pos(t_lst *lst, int element);
void	lstclear(t_lst **lst);
void	put_nb_top(t_lst **a, t_lst **b, int pos, int size);
int		is_max(t_lst *lst);
int		is_sort(t_lst *lst);
void	push_to_a(t_lst **a, t_lst **b);
void	push_to_b(t_lst **a, t_lst **b, int *tab, int size);
void	push_by_range(t_lst **a, t_lst **b, int range_min, int range_max);
int		*tab_for_range(t_lst *lst, int size);
int		is_min(t_lst *lst);
void	display_ok_ko(t_lst *a);
void	error_int(char **av, int ac);
double	racine(double x);
void	ft_strdel(char **ap);
void	ft_2dstrdel(char ***as);

#endif
