/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:53:36 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/11 14:38:55 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack, char c)
{
	t_list	*top;
	t_list	*prev_top;

	if (stack->size < 2)
		return ;
	top = pop_top(stack);
	prev_top = pop_top(stack);
	push_top(stack, top);
	push_top(stack, prev_top);
	if (c)
	{
		if (c == 'a')
			ft_putendl_fd("sa", 1);
		else
			ft_putendl_fd("sb", 1);
	}	
}

void	ft_push(t_stack *from, t_stack *to, char c)
{
	t_list	*node;

	if (from->size == 0)
		return ;
	node = pop_top(from);
	push_top(to, node);
	ft_index(from);
	ft_index(to);
	if (c)
	{
		if (c == 'a')
			ft_putendl_fd("pa", 1);
		else
			ft_putendl_fd("pb", 1);
	}
}

void	ft_rotate(t_stack *stack, enum e_type_rotate type, char c)
{
	t_list	*node;

	if (type == rotate)
	{
		node = pop_top(stack);
		push_bottom(stack, node);
		if (c == 'a')
			ft_putendl_fd("ra", 1);
		if (c == 'b')
			ft_putendl_fd("rb", 1);
	}	
	else if (type == rev_rotate)
	{
		node = pop_bottom(stack);
		push_top(stack, node);
		if (c == 'a')
			ft_putendl_fd("rra", 1);
		if (c == 'b')
			ft_putendl_fd("rrb", 1);
	}
}

void	ft_parallel_rotate(t_stack *a, t_stack *b, enum e_type_rotate type)
{
	ft_rotate(a, type, 0);
	ft_rotate(b, type, 0);
	if (type == rotate)
		ft_putendl_fd("rr", 1);
	else
		ft_putendl_fd("rrr", 1);
}

void	ft_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
