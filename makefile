# Variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SOURCES = test_open.c  main.c utils.c convert_digit.c split.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main

all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all