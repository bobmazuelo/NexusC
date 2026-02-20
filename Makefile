SRDIR = src/
TESTDIR = test/
SRC = $(wildcard $(SRDIR)*.c)
NAME = bin/NexusC
DSRC = $(addprefix $(SRDIR), $(SRC))
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
TFLAGS = -shared -fPIC -Iinclude
RM = rm -rf

all: $(NAME)

$(SRDIR)%.o: $(SRDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

lib: $(OBJS)
	$(CC) $(TFLAGS) -o $(TESTDIR)libtest.so $(OBJS)
	chmod +x $(TESTDIR)test.py

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TESTDIR)libtest.so

run:
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re