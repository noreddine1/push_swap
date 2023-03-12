/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:30:52 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 16:04:17 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_create_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->order = 1;
	node->moves = 0;
	node->is_longest = FALSE;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_top(t_stack *stack, t_list *node)
{
	if (stack->size == 0)
		stack->bottom = node;
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
	}
	stack->top = node;
	stack->size += 1;
}

t_list	*pop_top(t_stack *stack)
{
	t_list	*ret;

	if (stack->size == 0)
		return (NULL);
	ret = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = ret->prev;
		stack->top->next = NULL;
	}
	ret->prev = NULL;
	stack->size -= 1;
	return (ret);
}

void	push_bottom(t_stack *stack, t_list *node)
{
	if (stack->size == 0)
		stack->top = node;
	else
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
	}
	stack->bottom = node;
	stack->size += 1;
}

t_list	*pop_bottom(t_stack *stack)
{
	t_list	*ret;

	if (stack->size == 0)
		return (NULL);
	ret = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->bottom = ret->next;
		stack->bottom->prev = NULL;
	}
	ret->next = NULL;
	stack->size -= 1;
	return (ret);
}
