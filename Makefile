CC =	cc
FLAGS =	
NAME = push_swap
SRCS =	$(shell ls ./libft/*.c) \
		$(shell ls ./*.c)

OFILES =	$(SRCS:.c=.o)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

%.o: %.c 
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf  $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
