# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleskine <rleskine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:29:22 by rleskine          #+#    #+#              #
#    Updated: 2023/06/07 18:36:39 by rleskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS		=	checker
SRC			=	read_args.c \
				list_oprs.c list_oprs2.c \
				stack_ops.c stack_ops2.c stack_ops3.c \
				sort_utils.c print_utils.c \
				sort_basic.c sort_radix.c sort_insert.c \
				sort_brute.c sort_brute2.c
OBJ			=	$(SRC:.c=.o)
LIBS		=	./libft/libft.a 
LIBDIR		=	$(basename $(notdir $(LIBS)))
INCLUDE		=	$(addprefix -I, $(LIBDIR)) $(addprefix -L, $(LIBDIR))
LIBFLAGS	=	-lft -lm
CFLAGS		=	-Wall -Wextra -Werror
# -fsanitize=address
# remove fsanitize to make leaks work
NPROCS 		=	$(shell sysctl hw.ncpu | grep -o '[0-9]\+')
#MAKEFLAGS 	+= -j$(NPROCS)

CC =	cc

all: $(NAME)

$(NAME): %: %.c $(OBJ)
	$(CC) $(CFLAGS) $(GFX) $(INCLUDE) $(LIBFLAGS) -o $@ $< $(OBJ)

$(OBJ): %.o: %.c $(LIBS)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBS): %:
	$(MAKE) -j$(NPROCS) -C $(basename $(notdir $@))

bonus: $(BONUS)

$(BONUS): %: %.c $(OBJ)
	$(CC) $(CFLAGS) $(GFX) $(INCLUDE) $(LIBFLAGS) -o $@ $< $(OBJ)

clean:
	$(foreach lib, $(LIBDIR), $(MAKE) -C $(lib) clean)
	rm -rf $(OBJ)

fclean: clean
	$(foreach lib, $(LIBDIR), $(MAKE) -C $(lib) fclean)
	/bin/rm -f $(NAME) $(BONUS)

re: fclean all

.SILENT:
