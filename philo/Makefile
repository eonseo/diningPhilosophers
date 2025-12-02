CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRC = allocate.c \
	data_error.c \
	free.c \
	libft.c \
	main.c \
	init.c \
	monitoring_utils.c \
	monitoring.c \
	print.c \
	routine_utils.c \
	routine1.c \
	routine2.c \
	thread.c \
	time.c

OBJS = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
