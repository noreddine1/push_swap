/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:11:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/09 10:27:13 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	twoo_number_is(int x, int y)
{
	if (x > 0 && y > 0)
		return (positive);
	else if (x < 0 && y < 0)
		return (negative);
	else
		return (defferent);
}

static int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

static int	get_moves(t_list *current, t_list *next_order)
{
	int	x;
	int	y;
	int	res;

	y = next_order->index;
	x = current->index;
	res = twoo_number_is(x, y);
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (res == positive)
		return (max(x, y));
	else if (res == negative)
		return (max(x, y));
	else
		return (x + y);
}

void	best_moves(t_stack *a, t_stack *b, t_list *tab[])
{
	t_list		*current;
	t_list		*next_order;
	int			min_moves;
	enum e_bool	beging ;

	beging = TRUE;
	current = b->bottom;
	while (current)
	{
		next_order = get_node_of_next_order(a, current->order);
		current->moves = get_moves(current, next_order);
		if (current->moves < min_moves || beging == TRUE)
		{
			beging = FALSE;
			tab[0] = current;
			tab[1] = next_order;
			min_moves = current->moves;
		}
		current = current->next;
	}
}

void	back_b_to_a(t_stack *a, t_stack *b)
{
	t_list	*tab[2];
	int		res;
	int		x;
	int		y;

	while (b->size)
	{
		best_moves(a, b, tab);
		x = tab[0]->index;
		y = tab[1]->index;
		res = twoo_number_is(x, y);
		if (res == positive)
			while (a->top != tab[1] && b->top != tab[0])
				ft_parallel_rotate(a, b, rotate);
		else if (res == negative)
			while (a->top != tab[1] && b->top != tab[0])
				ft_parallel_rotate(a, b, rev_rotate);
		ft_index(a);
		ft_index(b);
		if (a->top != tab[1])
			put_to_top(a, tab[1], 'a');
		if (b->top != tab[0])
			put_to_top(b, tab[0], 'b');
		ft_push(b, a, 'a');
	}
}
