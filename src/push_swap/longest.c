/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:22:04 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 16:06:04 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_index_max_order(t_list	**tab, int size)
{
	int	i;
	int	index_max;
	int	max;

	i = 0;
	index_max = 0;
	max = tab[i]->order;
	while (i < size)
	{
		if (tab[i]->order > max)
		{
			index_max = i;
			max = tab[i]->order;
		}
		i++;
	}
	return (index_max);
}

void	set_longest_(t_list **tab, int i)
{
	while (i > 0)
	{
		tab[i]->is_longest = TRUE;
		i = tab[i]->index;
	}
	tab[0]->is_longest = TRUE;
	free(tab);
}

void	set_longest(t_stack *stack)
{
	t_list	**tab;
	t_list	*min;
	int		i;
	int		j;

	i = 1;
	min = ft_get_min(stack);
	tab = stack_to_table(stack, min);
	while (i < stack->size)
	{
		j = -1;
		while (++j < i)
		{
			if (tab[i]->data > tab[j]->data && tab[i]->order == tab[j]->order)
			{
				tab[i]->order += 1;
				tab[i]->index = j;
			}
		}
		i++;
	}
	i = ft_get_index_max_order(tab, stack->size);
	set_longest_(tab, i);
}

void	put_to_top(t_stack	*stack, t_list *node, char c)
{
	int	i;

	i = node->index;
	if (i < 0)
		while (stack->top != node)
			ft_rotate(stack, rev_rotate, c);
	else
		while (stack->top != node)
			ft_rotate(stack, rotate, c);
}

void	push_no_longest_to_b(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	t_list	*current;
	int		i;
	int		size;

	i = 0;
	size = a->size;
	current = a->top;
	while (i < size && current)
	{
		if (current->is_longest == FALSE)
		{
			tmp = current;
			current = current->prev;
			put_to_top(a, tmp, 'a');
			ft_push(a, b, 'b');
		}
		if (current && current->is_longest == TRUE)
			current = current->prev;
		i++;
	}
}
