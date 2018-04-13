NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o) $(SRCl:.c=.o)

SRCl = ft_lstiter.c ft_putendl.c ft_strequ.c ft_strnstr.c ft_lstmap.c ft_putendl_fd.c ft_striter.c \
ft_strrchr.c ft_atoi.c ft_lstnew.c ft_putnbr.c ft_striteri.c ft_strsplit.c ft_bzero.c ft_memalloc.c \
ft_putnbr_fd.c ft_strjoin.c ft_strstr.c ft_isalnum.c ft_memccpy.c ft_putstr.c  ft_strlcat.c \
ft_strsub.c ft_isalpha.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_strtrim.c ft_isascii.c \
ft_memcmp.c ft_strcat.c ft_strmap.c ft_tolower.c ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strmapi.c \
ft_toupper.c ft_isprint.c ft_memdel.c ft_strclr.c ft_strncat.c ft_itoa.c ft_memmove.c ft_strcmp.c \
ft_strncmp.c ft_lstadd.c ft_memset.c ft_strcpy.c ft_strncpy.c ft_lstdel.c ft_putchar.c ft_strdel.c \
ft_strnequ.c ft_lstdelone.c ft_putchar_fd.c ft_strdup.c ft_strnew.c get_next_line.c ft_strjoin_free.c \

SRC = arg_check_and_itoa.c check_errors_flags.c conversions_1.c conversions_2.c conversions_3.c \
conversions_4.c format.c format_flag.c ft_printf.c ft_printf2.c functions_zero.c is_flag.c parsing.c precision.c
SRCL = $(addprefix ./libft/, $(SRCl))
SRCS = $(addprefix ./src/, $(SRC))

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -c $(INC) $(SRCS) $(SRCL)
	@ar -rc $(NAME) $(INC) $(OBJ) $(LIB)
	@echo "\033[32m[✓] \033[33m libftprintf.a was created successfully"
	@mkdir -p obj
	@mv $(OBJ) obj

clean:
	rm -rf obj
	$(MAKE) -C libft/ clean
	@echo "\033[32m[✓] \033[33m all the object files were DESTROYED"

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C libft/ fclean
	@echo "\033[32m[✓] \033[33m libftprintf.a was DESTROYED"

re: fclean all
