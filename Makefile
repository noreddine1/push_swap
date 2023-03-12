# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 06:39:56 by nmaazouz          #+#    #+#              #
#    Updated: 2023/03/11 14:31:19 by nmaazouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
NAME_B = checker
INCS = -I ./includes
LIBFT_A = 	libft.a

OBJ_DIR = obj/

SRC_SH_DIR = src/shared/
SRC_PU_DIR = src/push_swap/
SRC_CH_DIR = src/checker/

SRC_SH = free.c   operations.c  parcing_utils.c  parsing.c  stack.c utils.c
SRC_PU = longest.c  push_swap.c  sort.c  sort_utils.c push_swap_utils.c
SRC_CH = checker.c

OBJ_SH = $(SRC_SH:%.c=%.o)
OBJ_PU = $(SRC_PU:%.c=%.o)
OBJ_CH = $(SRC_CH:%.c=%.o)
OBJ = $(OBJ_SH) $(OBJ_PU) 
OBJ_B = $(OBJ_SH) $(OBJ_CH)

SRC_SH_PATH = $(SRC_SH:%=$(SRC_SH_DIR)%)
SRC_PU_PATH = $(SRC_PU:%=$(SRC_PU_DIR)%)
SRC_CH_PATH = $(SRC_CH:%=$(SRC_CH_DIR)%)
SRC_PATH = $(SRC_PU_PATH) $(SRC_SH_PATH) 
SRC_PATH_B = $(SRC_SH_PATH) $(SRC_CH_PATH) 

OBJ_SH_PATH = $(addprefix $(OBJ_DIR), $(OBJ_SH))
OBJ_PU_PATH = $(addprefix $(OBJ_DIR), $(OBJ_PU))
OBJ_CH_PATH = $(addprefix $(OBJ_DIR), $(OBJ_CH))
OBJ_PATH = $(OBJ_SH_PATH) $(OBJ_PU_PATH)
OBJ_PATH_B = $(OBJ_SH_PATH) $(OBJ_CH_PATH)

all:	do_libft $(OBJ_DIR) $(NAME)

bonus:	do_libft $(OBJ_DIR) $(NAME_B)

$(OBJ_DIR):	
		@mkdir $(OBJ_DIR)
		@echo Create: Object directory

$(NAME):	$(OBJ_PATH)
			$(CC) $(OBJ_SH_PATH) $(OBJ_PU_PATH) *.a -o $@ -I includes
			@echo "\\n PUSH_SWAP COMPLETE \\n"

$(NAME_B):	$(OBJ_PATH_B)
			$(CC) $(OBJ_SH_PATH) $(OBJ_CH_PATH) *.a -o $@ -I includes

$(OBJ_SH_PATH):	$(SRC_SH_PATH)
				$(MAKE) $(OBJ_SH)


$(OBJ_PU_PATH):	$(SRC_PU_PATH)
				$(MAKE) $(OBJ_PU)

$(OBJ_CH_PATH):	$(SRC_CH_PATH)
				$(MAKE) $(OBJ_CH)


$(OBJ_SH):		$(LIBFT_A)
				$(CC) $(CFLAGS) $(INCS) -c -o $(OBJ_DIR)$@ $(SRC_SH_DIR)$(@:%.o=%.c)


$(OBJ_PU):		$(LIBFT_A)
				$(CC) $(CFLAGS) $(INCS) -c -o $(OBJ_DIR)$(basename $@).o $(SRC_PU_DIR)$(basename $@).c

$(OBJ_CH):		$(LIBFT_A)
				$(CC) $(CFLAGS) $(INCS) -c -o $(OBJ_DIR)$(basename $@).o $(SRC_CH_DIR)$(basename $@).c


do_libft:	
			@make -s -C libft/
			@cp ./libft/$(LIBFT_A) .

clean: 
			@rm -rf $(OBJ_DIR) $(LIBFT_A)
			@make -s -C libft/ clean

fclean:	clean
		@rm -f $(NAME)

re: clean all
