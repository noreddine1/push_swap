/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:56:57 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/11 14:35:59 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	**stack_to_table(t_stack *stack, t_list *node)
{
	t_list	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(t_list) * stack->size + 1);
	if (tab == NULL)
		return (NULL);
	while (i < stack->size)
	{
		tab[i] = node;
		i++;
		if (node->prev == NULL)
			node = stack->top;
		else
			node = node->prev;
	}
	tab[i] = NULL;
	i = 0;
	return (tab);
}

static void	swap_nodes(t_list **tab, int i, int j)
{
	t_list	*tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

void	order_stack(t_stack *stack)
{
	t_list	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = stack_to_table(stack, stack->bottom);
	while (tab[i])
	{
		j = i + 1;
		while (tab[j] != NULL)
		{
			if (tab[i]->data > tab[j]->data)
				swap_nodes(tab, i, j);
			j++;
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		tab[i]->order = i;
		i++;
	}
	free(tab);
}

t_list	*ft_get_min(t_stack *stack)
{
	t_list	*lst;
	t_list	*min;

	lst = stack->bottom;
	min = lst;
	lst = lst->next;
	while (lst)
	{
		if (lst->data < min->data)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
