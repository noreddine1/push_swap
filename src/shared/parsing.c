/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 09:59:02 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hash(char *key, long int *value, int count)
{
	int	hash;
	int	i;

	i = 0;
	hash = 0;
	while (key[i])
	{
		hash = hash + key[i];
		i++;
	}
	if (value != NULL)
		*value = ft_atoi(key);
	return (hash % count);
}

static int	count_args(char **args)
{
	int	count;

	count = 0;
	while (*args)
	{
		args++;
		count++;
	}
	return (count);
}

static int	check_(t_stack *stack, t_lst **map, char **args, int count)
{
	int			index;
	long int	*value;
	t_list		*node;

	while (*args)
	{
		value = malloc(sizeof(int));
		index = hash(*args, value, count);
		if (check_string_value(*args, *value) == 0)
			return (0);
		if (map[index] == NULL)
			map[index] = ft_lstnew(value);
		else
		{
			if (check_double(map[index], *value) == 0)
				return (0);
			ft_lstadd_back(&map[index], ft_lstnew(value));
		}
		node = ft_create_node(*value);
		ft_g_collector(node, MALLOC);
		push_bottom(stack, node);
		ft_g_collector(*args, MALLOC);
		args++;
	}
	return (1);
}

int	check(char **args, t_stack *stack)
{
	t_lst		**map;
	int			res;
	const int	count = count_args(args);

	map = ft_calloc(count, sizeof(t_lst *));
	if (!map)
		return (FALSE);
	res = check_(stack, map, args, count);
	free_hash_set(map, args, count);
	free(map);
	free(args);
	return (res);
}
