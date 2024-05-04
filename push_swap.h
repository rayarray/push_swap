/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:40:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/08 12:22:40 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node {
	int		data;
	void	*next;
}	t_node;

typedef struct s_stack {
	t_node	*a;
	t_node	*b;
	t_node	*i;
	t_node	*j;
	t_node	*t;
	t_node	*ops;
}	t_stack;

typedef struct s_brute {
	t_node	*n;
	int		ops;
	int		maxops;
	int		rec;
}	t_brute;

typedef struct s_insert
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		ops;
	int		nbr;
	int		max;
}	t_insert;

// read_args.c

t_node	*read_args(int ac, char **ag, int i, t_node *lst[2]);
int		check_args(int ac, char **ag);
int		dup_check(t_node *lst);

// print_utils.c

void	print_stack(t_node *n, char c);
void	print_ops(t_node *n);

// list_oprs.c

t_node	*add_node(int value);
t_node	*append_node(int value, t_node *prev);
t_node	*get_last(t_node *lst);
t_node	*remove_last(t_node *lst);
int		destroy_list(t_node *lst);

// list_oprs2.c

t_node	*copy_list(t_node *lst);
t_node	*add_to_end(int value, t_node *lst);
int		get_listsize(t_node *lst);
int		*cnv_to_arr(t_node *lst);
void	printlist(t_node *lst);

// stack_ops.c

t_stack	*init_stack(void);
t_stack	*swap(t_stack *s);
t_stack	*push(t_stack *s);
t_stack	*rot(t_stack *s);
t_stack	*rrot(t_stack *s);

// stack_ops2.c

t_stack	*a(t_stack *s, t_stack *(*op)(t_stack *s), int log);
t_stack	*b(t_stack *s, t_stack *(*op)(t_stack *s), int log);
t_stack	*r(t_stack *s, t_stack *(*op)(t_stack *s), int log);
int		is_sorted(t_node *lst);

// stack_ops3.c

t_stack	*copy_stack(t_stack *s);
int		free_stack(t_stack *s);

// sort_utils.c

void	rdx_revalue(t_node *n, int size, int i);
int		get_minmax(t_node *n, int order);
int		get_next(t_node *n, int nbr);
int		rot_minmax(t_node *n, int i, int order);
void	srt_3(t_stack *s, int order[3],
			t_stack *(*ab)(t_stack *, t_stack *(*)(t_stack *s), int));

// sort_brute.c

void	bruteforce3(t_stack *s, t_brute *b, int i);

// sort_brute2.c

void	add_solve(t_brute *b, t_node *n);
t_brute	*init_brute(int maxops);
void	get_bestsolve(t_brute *b, t_stack *s);

// sort_basic.c

void	intswap(int *a, int *b);
int		partition(int arr[], int low, int high);
void	quicksort(int arr[], int low, int high);
void	simplesort(t_stack *s, int size, int i);

// sort_radix.c

t_stack	*radix(t_stack *s, int size, int bits, int i);

// sort_insert.c

void	grd_ins_sort(t_stack *s);

#endif	/* PUSH_SWAP_H */
