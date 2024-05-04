/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:59:29 by rleskine          #+#    #+#             */
/*   Updated: 2023/06/08 12:57:42 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_main(t_stack *s, int ac, char **ag)
{
	if (s == NULL)
		return (0);
	if (check_args(ac, ag))
		s->a = read_args(ac, ag, 0, (t_node *[2]){NULL, NULL});
	if ((!s->a || dup_check(s->a) || !check_args(ac, ag)))
	{
		write(2, &"Error\n", 6);
		return (0);
	}
	if (s->a->next == NULL)
		return (0);
	s->i = s->a->next;
	free(s->a);
	s->a = s->i;
	s->i = NULL;
	return (1);
}

int	read_op(char *cmd, char c)
{
	if (read(0, &c, 1) && (c == 's' || c == 'p' || c == 'r'))
		cmd[0] = c;
	else
	{
		if (c == 0 || c == '\n')
			return (-1);
		return (0);
	}
	if (read(0, &c, 1) && (c == 'a' || c == 'b' || c == 'r' || c == 's'))
		cmd[1] = c;
	else
		return (0);
	if (read(0, &c, 1) && (c == 'a' || c == 'b' || c == 'r' || c == '\n'))
	{
		cmd[2] = c;
		if (c != '\n' && read(0, &c, 1) && c == '\n')
			cmd[3] = c;
		if (c != '\n')
			return (0);
		return (1);
	}
	else
		return (0);
}

t_stack	*cnv_op(t_stack *s, char *cmd)
{
	if (cmd[0] == 's' && cmd[1] == 'a' && cmd[2] == '\n')
		return (a(s, &swap, 1));
	if (cmd[0] == 's' && cmd[1] == 'b' && cmd[2] == '\n')
		return (b(s, &swap, 1));
	if (cmd[0] == 's' && cmd[1] == 's' && cmd[2] == '\n')
		return (r(s, &swap, 1));
	if (cmd[0] == 'p' && cmd[1] == 'a' && cmd[2] == '\n')
		return (a(s, &push, 1));
	if (cmd[0] == 'p' && cmd[1] == 'b' && cmd[2] == '\n')
		return (b(s, &push, 1));
	if (cmd[0] == 'r' && cmd[1] == 'a' && cmd[2] == '\n')
		return (a(s, &rot, 1));
	if (cmd[0] == 'r' && cmd[1] == 'b' && cmd[2] == '\n')
		return (b(s, &rot, 1));
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == '\n')
		return (r(s, &rot, 1));
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a' && cmd[3] == '\n')
		return (a(s, &rrot, 1));
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b' && cmd[3] == '\n')
		return (b(s, &rrot, 1));
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r' && cmd[3] == '\n')
		return (r(s, &rrot, 1));
	return (NULL);
}

int	main(int ac, char **ag)
{
	t_stack	*s;
	int		sorttype;
	char	cmd[4];

	s = init_stack();
	sorttype = init_main(s, ac, ag);
	if (s == NULL || (!sorttype && (!s || free_stack(s))))
		return (0);
	ac = read_op(cmd, 0);
	while (ac > 0 && cnv_op(s, cmd) == s)
		ac = read_op(cmd, 0);
	if (ac == 0)
		write(2, &"Error\n", 6);
	if (ac && s->b == NULL && is_sorted(s->a))
		write(1, &"OK\n", 3);
	else if (ac)
		write(1, &"KO\n", 3);
	if (s)
		free_stack(s);
	return (0);
}
