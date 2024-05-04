/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_brute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:35:43 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/07 18:26:19 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_op(t_stack *s, int op)
{
	if (op == 0 && s->a && s->a->next)
		return (1);
	else if (op == 1 && s->b && s->b->next)
		return (1);
	else if (op == 3 && s->b)
		return (1);
	else if (op == 4 && s->a)
		return (1);
	else if ((op == 5 || op == 8) && s->a && s->a->next)
		return (1);
	else if ((op == 6 || op == 9) && s->b && s->b->next)
		return (1);
	else if ((op == 2 || op == 7 || op == 10)
		&& s->a && s->a->next && s->b && s->b->next)
		return (1);
	return (0);
}

void	make_op(t_stack *s, int op, int log)
{
	if (op == 0)
		a(s, &swap, log);
	else if (op == 1)
		b(s, &swap, log);
	else if (op == 2)
		r(s, &swap, log);
	else if (op == 3)
		a(s, &push, log);
	else if (op == 4)
		b(s, &push, log);
	else if (op == 5)
		a(s, &rot, log);
	else if (op == 6)
		b(s, &rot, log);
	else if (op == 7)
		r(s, &rot, log);
	else if (op == 8)
		a(s, &rrot, log);
	else if (op == 9)
		b(s, &rrot, log);
	else if (op == 10)
		r(s, &rrot, log);
}

void	revert_op(t_stack *s, int op, int log)
{
	if (op == 0)
		a(s, &swap, 0);
	else if (op == 1)
		b(s, &swap, 0);
	else if (op == 2)
		r(s, &swap, 0);
	else if (op == 3)
		b(s, &push, 0);
	else if (op == 4)
		a(s, &push, 0);
	else if (op == 5)
		a(s, &rrot, 0);
	else if (op == 6)
		b(s, &rrot, 0);
	else if (op == 7)
		r(s, &rrot, 0);
	else if (op == 8)
		a(s, &rot, 0);
	else if (op == 9)
		b(s, &rot, 0);
	else if (op == 10)
		r(s, &rot, 0);
	if (log)
		s->ops = remove_last(s->ops);
}

int	check_solve(t_stack *s, int i)
{
	while (i < 11)
	{
		if (check_op(s, i))
		{
			make_op(s, i, 0);
			if (s->b == NULL && s->a && s->a->data == 0 && is_sorted(s->a))
			{
				revert_op(s, i, 0);
				return (i);
			}
			revert_op(s, i, 0);
		}
		i++;
	}
	return (-1);
}

void	bruteforce3(t_stack *s, t_brute *b, int i)
{
	if (get_listsize(s->ops) >= b->maxops
		|| (b->n != NULL && get_listsize(s->ops) >= b->ops))
		return ;
	i = check_solve(s, 0);
	if (i > -1)
	{
		make_op(s, i, 1);
		add_solve(b, s->ops);
		revert_op(s, i, 1);
		if (b->rec)
			return ;
	}
	i = 11;
	while (i-- >= 0)
	{
		if (check_op(s, i))
		{
			make_op(s, i, 1);
			bruteforce3(s, b, 0);
			revert_op(s, i, 1);
		}
	}
	b->rec = 1;
	if (!s->ops)
		get_bestsolve(b, s);
}
