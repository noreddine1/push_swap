/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:39:27 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 15:58:35 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_string_value(char *str, long int value)
{
	int		i;

	i = 0;
	if (value < INT32_MIN || value > INT32_MAX)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_double(t_lst *lst, long int value)
{
	t_lst	*current;
	int		cur_int;

	current = lst;
	while (current != NULL)
	{
		cur_int = *(int *)(current->content);
		if (*(int *)(current->content) == value)
			return (0);
		current = current->next;
	}
	return (1);
}
