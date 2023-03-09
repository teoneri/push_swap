GCC     = gcc
CFLAGS  = -g -Wall -Wextra -Werror -fPIC -fPIE
FILES   = SRC/push_swap.c SRC/check_args.c SRC/operations.c SRC/operations2.c SRC/sort.c SRC/lis.c SRC/utils.c SRC/utils2.c SRC/sort_tool.c SRC/move.c \
			SRC/free.c
SRC_BONUS   = SRC/checker.c SRC/check_args.c SRC/check_ops.c SRC/check_ops_two.c
NAME    = push_swap
BONUS_NAME = checker
PRINTF  = ft_printf
LIBRARY = ft_printf/libftprintf.a
RM  = rm -f
OBJECTS=$(FILES:.c=.o)
BONUS_OBJ = $(SRC_BONUS:.c=.o)

all:    $(NAME)
$(NAME):    $(OBJECTS)
			@make -C $(PRINTF)
			$(GCC) $(CFLAGS) $(OBJECTS) $(LIBRARY) -o $(NAME)
clean:
			@$(RM) $(OBJECTS)
			@$(RM) $(BONUS_OBJ)
			@make clean -C $(PRINTF)
            
fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(BONUS_NAME)
			@$(RM) $(LIBRARY)
            
re:     fclean all
bonus:		all $(BONUS_OBJ)
			$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(LIBRARY)
.PHONY:     all clean fclean re