CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror
INCLUDES ?= includes/
NAME = bsq

.SUFFIXES: .c .o

OBJS = srcs/convert.o srcs/dict.o srcs/ft_split.o srcs/ft.o srcs/main.o srcs/tab.o
SRCS = srcs/convert.c srcs/dict.c srcs/ft_split.c srcs/ft.c srcs/main.c srcs/tab.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -I$(INCLUDES) -o $(NAME)

srcs/.c srcs/.o:
	$(CC) $(CFLAGS) -c $(SRCS) -I$(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
