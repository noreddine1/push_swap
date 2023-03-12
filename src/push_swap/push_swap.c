/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:04:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/12 16:01:58 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;

	if (ac < 2)
		return (0);
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	args = ft_get_args(av);
	if (args == NULL)
		ft_error();
	if (check(args, &stack_a) == 0)
		ft_error();
	if (ft_is_sorted(&stack_a) == 1)
		exit(0);
	sort(&stack_a, &stack_b);
	ft_g_collector(NULL, FREE);
}
