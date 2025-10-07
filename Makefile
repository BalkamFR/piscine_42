CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
INCLUDES ?= includes/
NAME = bsq

.SUFFIXES: .c .o

OBJS = $(SOURCES:.c=.o)
SRCS = srcs/check_coords.c \
	srcs/free.c \
	srcs/main.c \
	srcs/map_check.c \
	srcs/params.c \
	srcs/utils.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -I$(INCLUDES) -o $(NAME)

srcs/.c srcs/.o:
	$(CC) $(CFLAGS) -c $(SRCS) -I$(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all