/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:37:38 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/10/31 22:01:08 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<libc.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size_needle;

	i = 0;
	size_needle = ft_strlen(needle);
	if (!size_needle || (!haystack && !len))
		return ((char *)haystack);
	while (haystack[i] && i + size_needle <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (!ft_strncmp(haystack + i, needle, size_needle))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
