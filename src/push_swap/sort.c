/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:49:24 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/09 10:40:41 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*get_node_of_next_order(t_stack *a, int order)
{
	int		next_order;
	t_list	*current;
	t_list	*ret;

	next_order = 0;
	current = a->bottom;
	while (current)
	{
		if (current->order > order)
		{
			if (current->order < next_order || next_order == 0)
			{
				ret = current;
				next_order = current->order;
			}
		}
		current = current->next;
	}
	if (next_order == 0)
		return (ft_get_min(a));
	return (ret);
}

static void	sort_3_element(t_stack *a)
{
	const int	top = a->top->data;
	const int	bottom = a->bottom->data;
	const int	midle = a->top->prev->data;

	if (top > bottom)
	{
		if (top > midle)
			ft_rotate(a, rotate, 'a');
		else
			ft_rotate(a, rev_rotate, 'a');
	}
	else
		ft_swap(a, 'a');
	if (ft_is_sorted(a) == FALSE)
		sort_3_element(a);
}

static void	sort_5_element(t_stack *a, t_stack *b)
{
	order_stack(a);
	while (a->size != 3)
		ft_push(a, b, 'b');
	sort_3_element(a);
	back_b_to_a(a, b);
	put_to_top(a, ft_get_min(a), 'a');
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ft_swap(a, 'a');
	else if (a->size <= 3)
		sort_3_element(a);
	else if (a->size <= 5)
		sort_5_element(a, b);
	else
	{
		set_longest(a);
		order_stack(a);
		ft_index(a);
		push_no_longest_to_b(a, b);
		back_b_to_a(a, b);
		put_to_top(a, ft_get_min(a), 'a');
	}
}
