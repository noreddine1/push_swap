/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:57:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/11 14:50:10 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_op_(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		ft_swap(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_swap(b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		ft_push(b, a, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		ft_push(a, b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ft_rotate(a, rotate, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_rotate(b, rotate, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_rotate(a, rev_rotate, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_rotate(b, rev_rotate, 0);
	else
		ft_error();
}

void	run_opr(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "rrr\n", 4))
	{
		ft_rotate(a, rev_rotate, 0);
		ft_rotate(b, rev_rotate, 0);
		return ;
	}
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		ft_rotate(a, rotate, 0);
		ft_rotate(b, rotate, 0);
		return ;
	}
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		ft_swap(a, 0);
		ft_swap(b, 0);
		return ;
	}
	run_op_(a, b, str);
}

void	checker(t_stack	*a, t_stack *b)
{
	char	*str;

	str = get_next_line(0);
	ft_g_collector(str, MALLOC);
	while (str)
	{
		run_opr(a, b, str);
		str = get_next_line(0);
		ft_g_collector(str, MALLOC);
	}
}

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
	{
		ft_error();
		free(args);
	}
	checker(&stack_a, &stack_b);
	if (ft_is_sorted(&stack_a) == 1 && !stack_b.size)
		ft_putendl_fd("ok", 1);
	else
		ft_putendl_fd("ko", 1);
	ft_g_collector(NULL, FREE);
}
