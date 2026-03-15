CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
INCLUDES ?= includes/
NAME = bsq

SRCS = srcs/check_coords.c \
	srcs/free.c \
	srcs/main.c \
	srcs/create_map.c \
	srcs/map_check.c \
	srcs/params.c \
	srcs/utils.c \
	srcs/utils2.c \
	srcs/find_square.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all