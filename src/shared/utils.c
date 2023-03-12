/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:04:02 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 13:43:34 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_get_args(char **args)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	join = NULL;
	while (args[++i])
	{
		j = 0;
		while (args[i][j] == ' ')
			j++;
		if (args[i][j] == 0)
			return (NULL);
		join = ft_strjoin(join, args[i]);
		ft_g_collector(join, MALLOCED);
	}
	args = ft_split(join, ' ');
	i = 0;
	while (args[i])
		ft_g_collector(args[i++], MALLOCED);
	return (args);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_g_collector(NULL, FREE);
	exit(1);
}

int	ft_is_sorted(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size == 0)
		return (0);
	first = stack->top;
	second = first->prev;
	while (second != 0)
	{
		if (second->data < first->data)
			return (0);
		first = first->prev;
		second = first->prev;
	}
	return (1);
}

void	ft_index(t_stack *stack)
{
	t_list	*top;
	t_list	*bottom;
	int		i;

	i = 0;
	top = stack->top;
	bottom = stack->bottom;
	while (i < stack->size / 2)
	{
		top->index = i;
		i++;
		bottom->index = -i;
		top = top->prev;
		bottom = bottom->next;
	}
	if (stack->size % 2 != 0)
		top->index = i;
}
