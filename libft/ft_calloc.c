/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:39:47 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/10/18 09:38:50 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	all_size;

	all_size = count * size;
	ptr = malloc (all_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, all_size);
	return (ptr);
}
