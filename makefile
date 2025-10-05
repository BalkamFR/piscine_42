CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SOURCES = open_files.c  main.c utils.c utils2.c convert_digit.c convert_digit_2.c split.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main

all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

