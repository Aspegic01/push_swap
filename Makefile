CC =	cc
FLAGS =	
NAME = push_swap
BNAME = checker
SRCS =	$(shell ls ./libft/*.c) \
		$(shell ls ./main/*.c) \
		$(shell ls ./sort/*.c) \
		$(shell ls ./utils/*.c) \
		$(shell ls ./operation/*.c)

BONUS = $(shell ls ./libft/*.c) \
		$(shell ls ./Get_next_line/*.c) \
		$(shell ls ./bonus/*.c)

OFILES = $(SRCS:.c=.o)
BOFILES = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOFILES)
	$(CC) $(FLAGS) $(BOFILES) -o $(BNAME)

clean:
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

re_bonus : fclean bonus

.PHONY: all bonus clean fclean re
