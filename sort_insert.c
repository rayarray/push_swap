/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:06:42 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/07 14:55:11 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_ops(t_stack *s, t_insert ops)
{
	if (get_listsize(s->b) < 3)
	{
		while (ops.ra--)
			a(s, &rot, 1);
		while (ops.rra--)
			a(s, &rrot, 1);
		b(s, &push, 1);
		if (get_listsize(s->b) == 3)
			srt_3(s, (int [3]){2, 1, 0}, &b);
		return ;
	}
	while (ops.ra > 0 && ops.rb > 0 && ops.ra-- && ops.rb--)
		r(s, &rot, 1);
	while (ops.rra > 0 && ops.rrb > 0 && ops.rra-- && ops.rrb--)
		r(s, &rrot, 1);
	while (ops.ra--)
		a(s, &rot, 1);
	while (ops.rra--)
		a(s, &rrot, 1);
	while (ops.rb--)
		b(s, &rot, 1);
	while (ops.rrb--)
		b(s, &rrot, 1);
	b(s, &push, 1);
}

int	get_b_rot(t_node *n, int nbr, int i)
{
	int	next;
	int	size;

	if (n == NULL)
		return (0);
	if (n && !n->next)
	{
		if (nbr > n->data)
			return (0);
		return (1);
	}
	size = get_listsize(n);
	next = get_next(n, nbr);
	while (n && n->data != next)
	{
		i++;
		n = n->next;
	}
	if (i < size - i)
		return (i);
	return (-(size - i));
}

t_insert	get_iops(t_stack *s, int pos, t_node *n)
{
	t_insert	ops;

	ft_bzero(&ops, sizeof(t_insert));
	if (pos <= ((get_listsize(s->a)) - pos))
		ops.ra = pos;
	else
		ops.rra = get_listsize(s->a) - pos;
	ops.ops = get_b_rot(s->b, n->data, 0);
	if (ops.ops > 0)
		ops.rb = ops.ops;
	else
		ops.rrb = -ops.ops;
	if (ops.ra > 0 && ops.rb > 0)
		ops.ops = minmax(2, ops.ra, ops.rb) + 1;
	else if (ops.rra > 0 && ops.rrb > 0)
		ops.ops = minmax(2, ops.rra, ops.rrb) + 1;
	else
		ops.ops = ops.ra + ops.rb + ops.rra + ops.rrb + 1;
	return (ops);
}

t_insert	find_best(t_stack *s, int i, int max)
{
	t_insert	best;
	t_insert	swap;
	t_node		*n;

	n = s->a;
	while (n->data >= max - 2)
	{
		i++;
		n = n->next;
	}
	best = get_iops(s, i, n);
	n = n->next;
	while (n && ++i)
	{
		if (n->data < max - 2)
		{
			swap = get_iops(s, i, n);
			if (swap.ops < best.ops)
				best = swap;
		}
		n = n->next;
	}
	return (best);
}

void	grd_ins_sort(t_stack *s)
{
	t_insert	ops;
	int			max;

	max = get_minmax(s->a, 1);
	while (get_listsize(s->a) > 3)
	{
		ops = find_best(s, 0, max);
		make_ops(s, ops);
	}
	srt_3(s, (int [3]){0, 1, 2}, &a);
	ops.ops = rot_minmax(s->b, 0, 1);
	while (ops.ops > 0 && ops.ops--)
		b(s, &rot, 1);
	while (ops.ops < 0 && ops.ops++)
		b(s, &rrot, 1);
	while (s->b)
		a(s, &push, 1);
}
