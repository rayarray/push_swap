/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:59:29 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/07 18:21:39 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_main(t_stack *s, int ac, char **ag)
{
	if (check_args(ac, ag))
		s->a = read_args(ac, ag, 0, (t_node *[2]){NULL, NULL});
	if ((!s->a || dup_check(s->a) || !check_args(ac, ag)))
	{
		write(2, &"Error\n", 6);
		return (free_stack(s) - 1);
	}
	s->i = s->a->next;
	free(s->a);
	s->a = s->i;
	s->i = NULL;
	if (s->a == NULL || is_sorted(s->a))
		return (free_stack(s) - 1);
	rdx_revalue(s->a, get_listsize(s->a), 0);
	if (get_listsize(s->a) <= 4)
		return (get_listsize(s->a) + 1);
	else if (get_listsize(s->a) <= 6)
		return (get_listsize(s->a) + 4);
	else
		return (-1);
}

int	main(int ac, char **ag)
{
	t_stack	*s;
	int		sorttype;

	s = init_stack();
	if (s == NULL)
		return (12);
	sorttype = init_main(s, ac, ag);
	if (!sorttype)
		return (0);
	else if (sorttype > 0)
		bruteforce3(s, init_brute(sorttype), 0);
	else if (sorttype == -1)
		grd_ins_sort(s);
	print_ops(s->ops);
	free_stack(s);
}
