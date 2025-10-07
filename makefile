CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
INCLUDES ?= includes/
NAME = bsq

.SUFFIXES: .c .o

OBJS = $(SOURCES:.c=.o)
SRCS = srcs/map_check.c srcs/test.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -I$(INCLUDES) -o $(NAME)

srcs/.c srcs/.o:
	$(CC) $(CFLAGS) -c $(SRCS) -I$(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
