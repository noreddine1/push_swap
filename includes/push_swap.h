/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:47:21 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/10 13:08:32 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef enum e_type_rotate{rev_rotate, rotate}	t_type_rotate;
typedef enum e_bool{FALSE, TRUE}	t_bool;
typedef enum e_g_type{MALLOC,FREE}	t_g_type;
enum e_twoo_number_is{negative, positive, defferent};

typedef struct s_list	t_list;
struct s_list {
	int		data;
	t_bool	is_longest;
	t_list	*next;
	t_list	*prev;
	int		index;
	int		moves;
	int		order;
};

typedef struct s_stack	t_stack;
struct s_stack{
	t_list	*top;
	t_list	*bottom;
	int		size;
};

typedef struct s_hash	t_hash;
struct s_hash{
	int	key;
	int	value;
};

//-----stack.c
// void	ft_init_stack(t_stack *stack);
t_list	*ft_create_node(int data);
void	push_top(t_stack *stack, t_list *node);
t_list	*pop_top(t_stack *stack);
void	push_bottom(t_stack *stack, t_list *node);
t_list	*pop_bottom(t_stack *stack);
void	print_stck(t_stack *stack); //delete it

//-----operations
void	ft_swap(t_stack *stack, char c);
void	ft_push(t_stack *from, t_stack *to, char c);
void	ft_rotate(t_stack *stack, enum e_type_rotate type, char c);
void	ft_parallel_rotate(t_stack *a, t_stack *b, enum e_type_rotate type);
void	ft_init_stack(t_stack *stack);

//-----parsing.c
int		check_string_value(char *str, long int value);
int		hash(char *key, long int *value, int count);
int		check_double(t_lst *lst, long int value);
int		check(char **args, t_stack *stack);

//------------utils.c
char	**ft_get_args(char **args);
int		ft_is_sorted(t_stack *stack);
void	ft_error(void);

//-----------push_swap_utils.c
t_list	**stack_to_table(t_stack *stack, t_list *node);
void	order_stack(t_stack *stack);
void	ft_index(t_stack *stack);
t_list	*ft_get_min(t_stack *stack);

//---------longest.c
void	set_longest(t_stack *stack);
void	put_to_top(t_stack	*stack, t_list *node, char c);
void	push_no_longest_to_b(t_stack *a, t_stack *b);

//--------sort.c
t_list	*get_node_of_next_order(t_stack *a, int order);
void	sort(t_stack *a, t_stack *b);

//--------sort.c
void	back_b_to_a(t_stack *a, t_stack *b);
// void	best_moves(t_stack *a, t_stack *b, t_list *tab[]);

//---------free.c
void	ft_free(void *ptr);
void	free_hash_set(t_lst **map, char **args, int count);
int		ft_g_collector(void *ptr, t_g_type type);

#endif