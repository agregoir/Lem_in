# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 13:47:31 by csimon            #+#    #+#              #
#    Updated: 2017/10/25 13:47:32 by csimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
FLAG = -Wall -Wextra -Werror
OBJ = $(SRCC:.c=.o)

SRC = main.c parser_acquire.c parser_check.c parser_check2.c parser_acquire2.c parser_acquire3.c find_path.c manage_list.c print_path.c set_weight.c
SRCC = $(addprefix ./srcs/, $(SRC))

all: $(NAME)

$(NAME): $(SRCC)
	$(MAKE) -C includes/libftprintf
	@gcc -o $(NAME) $(FLAG) $(SRCC) includes/libftprintf/libftprintf.a
	@echo "\033[32m[✓] \033[33m lem_in was created successfully"

clean:
	$(MAKE) -C includes/libftprintf/ clean
	@echo "\033[32m[✓] \033[33m all the object files were DESTROYED"

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C includes/libftprintf/ fclean
	@echo "\033[32m[✓] \033[33m lem_in was DESTROYED"

re: fclean all


