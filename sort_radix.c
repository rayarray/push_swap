/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:48:34 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/07 15:04:59 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*radix(t_stack *s, int size, int bits, int i)
{
	int	j;

	j = 0;
	while (((size - 1) >> bits) > 0)
		bits++;
	while (j < bits)
	{
		i = 0;
		i = 0;
		while (i < size)
		{
			if ((s->a->data >> j) & 1)
				a(s, &rot, 1);
			else
				b(s, &push, 1);
			i++;
		}
		while (s->b)
			a(s, &push, 1);
		j++;
	}
	return (s);
}
