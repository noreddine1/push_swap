/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:55:04 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/02/25 02:23:28 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <assert.h>
#include <stdio.h>
int main()
{
    //--------------------push/pop_top
    {
        t_stack stack;
        t_list  *node;

        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(1));
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 1);
        push_top(&stack, ft_create_node(2));
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->prev->data == 1);
        assert(stack.top->data == 2);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->next->data == 2);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 2);
        push_top(&stack, ft_create_node(3));
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->prev->data == 2);
        assert(stack.top->data == 3);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->next->data == 2);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 3);
        puts("complete push_top");
        node = pop_top(&stack);
        //---node
        assert(node->data == 3);
        assert(node->next == NULL);
        assert(node->prev == NULL);
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->prev->data == 1);
        assert(stack.top->data == 2);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->next->data == 2);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 2);
        node = pop_top(&stack);
        //---node
        assert(node->data == 2);
         //---top
        assert(stack.top->next == NULL);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 1);
        node = pop_top(&stack);
        assert(node->data == 1);
        //--top
        assert(!stack.top);
        //--bottom
        assert(!stack.bottom);
        //--size
        assert(stack.size == 0);
        pop_top(&stack);
        puts("complete pop_top");
    }
    //--------------------push/pop_bottom
    {
        t_stack stack;
        t_list  *node;

        ft_init_stack(&stack);
        push_bottom(&stack, ft_create_node(1));
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 1);
        push_bottom(&stack, ft_create_node(2));
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->prev->data == 2);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->next->data == 1);
        assert(stack.bottom->data == 2);
        //---size
        assert(stack.size == 2);
        push_bottom(&stack, ft_create_node(3));
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->prev->data == 2);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->next->data == 2);
        assert(stack.bottom->data == 3);
        //---size
        assert(stack.size == 3);
        puts("complete push_bottom");
        node = pop_bottom(&stack);
        //---node
        assert(node->data == 3);
        assert(node->next == NULL);
        assert(node->prev == NULL);
        //---top
        assert(stack.top->next == NULL);
        assert(stack.top->prev->data == 2);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->next->data == 1);
        assert(stack.bottom->data == 2);
        //---size
        assert(stack.size == 2);
        node = pop_bottom(&stack);
        //---node
        assert(node->data == 2);
         //---top
        assert(stack.top->next == NULL);
        assert(stack.top->data == 1);
        //---bottom
        assert(stack.bottom->prev == NULL);
        assert(stack.bottom->data == 1);
        //---size
        assert(stack.size == 1);
        node = pop_bottom(&stack);
        assert(node->data == 1);
        //--top
        assert(!stack.top);
        //--bottom
        assert(!stack.bottom);
        //--size
        assert(stack.size == 0);
        pop_bottom(&stack);
        puts("complete pop_bottom");
    }
    //-------------------swap
    {
        t_stack stack;
        
        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(3));
        push_top(&stack, ft_create_node(1));
        push_top(&stack, ft_create_node(2));
        
        ft_swap(&stack, 0);
        assert(stack.top->data == 1);
        assert(stack.top->prev->data == 2);
        assert(stack.bottom->data == 3);
        assert(stack.top->next == NULL);
        assert(stack.bottom->prev == NULL);
        puts("complete swap");
    }
    //-------------------push
    {
        t_stack from;
        t_stack to;

        ft_init_stack(&from);
        ft_init_stack(&to);
        push_top(&from, ft_create_node(1));
        ft_push(&from, &to, 0);

        assert(from.size == 0);
        assert(from.top == NULL);
        assert(to.size == 1);
        assert(to.top->data == 1);
        puts("complete push");
    }
    //---------rotate/rev_rotate
    {
        t_stack stack;
        
        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(2));
        push_top(&stack, ft_create_node(1));
        push_top(&stack, ft_create_node(3));
        
        
        ft_rotate(&stack, rotate, 0);
        assert(stack.top->data == 1);
        assert(stack.bottom->data == 3);
        print_stck(&stack);
        puts("complete rotate");
        ft_rotate(&stack, rev_rotate, 0);
        assert(stack.top->data == 3);
        assert(stack.bottom->data == 2);
        print_stck(&stack);
        puts("complete rev_rotate");
    }
    //---------index
    {
       t_stack stack;
        
        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(-1));
        push_top(&stack, ft_create_node(0));
        print_stck(&stack);
        
        ft_index(&stack);
        assert(stack.top->index == 0);
        assert(stack.bottom->index == -1);
        puts("commplete index with paire size");
        
        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(-1));
        push_top(&stack, ft_create_node(1));
        push_top(&stack, ft_create_node(0));
        print_stck(&stack);
        
        ft_index(&stack);
        assert(stack.top->index == 0);
        assert(stack.bottom->next->index == 1);
        assert(stack.top->prev->index == 1);
        assert(stack.bottom->index == -1);
        puts("commplete index with impaire size");
    }
    //---------statck_to_table
    {
        t_stack stack;
        t_list  **tab;
        
        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(2));
        push_top(&stack, ft_create_node(1));
        push_top(&stack, ft_create_node(3));
        
        tab = stack_to_table(&stack, stack.bottom->next);
        assert((*tab++)->data == 1);
        assert((*tab++)->data == 2);
        assert((*tab++)->data == 3);
        puts("complete stack_to_table");
    }
    //------ft_get_min
    {
        t_stack stack;

        ft_init_stack(&stack);
        push_top(&stack, ft_create_node(2));
        push_top(&stack, ft_create_node(1));
        push_top(&stack, ft_create_node(3));
        t_list *min = ft_get_min(&stack);
        assert(min->data == 1);
        puts("complete ft_get_min");
    }
    //-------set_longest
    {
        t_stack stack;

        ft_init_stack(&stack);
        push_bottom(&stack, ft_create_node(2));
        push_bottom(&stack, ft_create_node(1));
        push_bottom(&stack, ft_create_node(5));
        push_bottom(&stack, ft_create_node(3));
        push_bottom(&stack, ft_create_node(4));
        
        set_longest(&stack);
        t_list  *node = stack.bottom;
        assert(node->is_longest == true);
        node = node->next;
        assert(node->is_longest == true);
        node = node->next;
        assert(node->is_longest == false);
        node = node->next;
        assert(node->is_longest == true);
        node = node->next;
        assert(node->is_longest == false);
        puts("complete set_longest");
    }
    //--------put_to_top
    {
       t_stack stack;

       ft_init_stack(&stack);

        push_bottom(&stack, ft_create_node(3));
        push_bottom(&stack, ft_create_node(4));
        t_list  *node = ft_create_node(1);
        push_bottom(&stack, node);
        push_bottom(&stack, ft_create_node(2));

        ft_index(&stack);
        put_to_top(&stack, node);
        assert(stack.top == node);
        assert(stack.top->prev->data == 2);
        assert(stack.bottom->data == 4);
        assert(stack.bottom->next->data == 3);
        puts("complete put_top");
    }
    //--------push_no_longes_to_b
    {
        t_stack a, b;

        ft_init_stack(&a);
        ft_init_stack(&b);
        push_bottom(&a, ft_create_node(2));
        push_bottom(&a, ft_create_node(1));
        push_bottom(&a, ft_create_node(5));
        push_bottom(&a, ft_create_node(3));
        push_bottom(&a, ft_create_node(4));
        
        ft_index(&a);
        set_longest(&a);
        push_no_longest_to_b(&a, &b);
        assert(b.top->data == 5);
        assert(b.top->prev->data == 2);
        puts("complete push_no_longest_to_b");
    }
}