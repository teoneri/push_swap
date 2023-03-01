GCC     = gcc
CFLAGS  = -g -Wall -Wextra -Werror
FILES   = SRC/push_swap.c SRC/check_args.c SRC/operations.c SRC/operations2.c SRC/sort.c SRC/lis.c SRC/utils.c
BONUS   = checker.c
NAME    = push_swap
PRINTF  = ft_printf
LIBRARY = ft_printf/libftprintf.a
RM  = rm -f
OBJECTS=$(FILES:.c=.o)

all:    $(NAME)
$(NAME):    $(OBJECTS)
			@make -C $(PRINTF)
			$(GCC) $(CFLAGS) $(OBJECTS) $(LIBRARY) -o $(NAME)
clean:
			@$(RM) $(OBJECTS)
			@make clean -C $(PRINTF)
            
fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(LIBRARY)
            
re:     fclean all
bonus: all
.PHONY:     all clean fclean re