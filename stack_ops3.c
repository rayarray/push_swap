/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:56:15 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/07 14:57:42 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_stack(t_stack *s)
{
	t_stack	*copy;

	copy = init_stack();
	copy->a = copy_list(s->a);
	copy->b = copy_list(s->b);
	copy->ops = copy_list(s->ops);
	return (copy);
}

int	free_stack(t_stack *s)
{
	if (!s)
		return (1);
	if (s->a)
		destroy_list(s->a);
	if (s->b)
		destroy_list(s->b);
	if (s->ops)
		destroy_list(s->ops);
	free(s);
	return (1);
}
