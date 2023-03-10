/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:20:25 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 16:06:34 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_hash_set(t_lst **map, char **args, int count)
{
	int	index;

	while (*args)
	{
		index = hash(*args, NULL, count);
		if (map[index] != NULL)
			ft_lstclear(map + index, free);
		args++;
	}
}

int	ft_g_collector(void *ptr, t_g_type type)
{
	static t_lst	*head;

	if (type == MALLOCED)
	{
		ft_lstadd_front(&head, ft_lstnew(ptr));
		return (0);
	}
	ft_lstclear(&head, free);
	return (0);
}
