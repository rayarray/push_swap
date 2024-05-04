/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:39:41 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/07 14:00:40 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rdx_revalue(t_node *n, int size, int i)
{
	int	*arr;

	arr = cnv_to_arr(n);
	quicksort(arr, 0, size - 1);
	while (n)
	{
		i = 0;
		while (n->data != arr[i])
			i++;
		n->data = i;
		n = n->next;
	}
	free(arr);
}

int	get_minmax(t_node *n, int order)
{
	int	minmax;

	if (n)
		minmax = n->data;
	n = n->next;
	while (n)
	{
		if ((order == 0 && minmax > n->data)
			|| (order && minmax < n->data))
			minmax = n->data;
		n = n->next;
	}
	return (minmax);
}

int	get_next(t_node *n, int nbr)
{
	int		next;

	next = get_minmax(n, 0);
	if (next > nbr)
		return (get_minmax(n, 1));
	while (n)
	{
		if (n->data > next && n->data < nbr)
			next = n->data;
		n = n->next;
	}
	return (next);
}

int	rot_minmax(t_node *n, int i, int order)
{
	int	first;
	int	size;

	first = get_minmax(n, order);
	size = get_listsize(n);
	while (n && n->data != first)
	{
		i++;
		n = n->next;
	}
	if (i <= size - i)
		return (i);
	return (-(size - i));
}

void	srt_3(t_stack *s, int order[3],
	t_stack *(*ab)(t_stack *, t_stack *(*)(t_stack *s), int))
{
	if (ab == &a)
		s->t = copy_list(s->a);
	else
		s->t = copy_list(s->b);
	rdx_revalue(s->t, 3, 0);
	if (s->t->data == order[2])
	{
		if (((t_node *)(s->t->next))->data == order[1])
			ab(s, &swap, 10);
		ab(s, &rrot, 10);
	}
	if (s->t->data == order[0] && ((t_node *)(s->t->next))->data == order[2])
	{
		ab(s, &rrot, 10);
		ab(s, &swap, 10);
	}
	else if (s->t->data == order[1])
	{
		if (((t_node *)(s->t->next))->data == order[0])
			ab(s, &swap, 10);
		else
			ab(s, &rrot, 10);
	}
	destroy_list(s->t);
}
