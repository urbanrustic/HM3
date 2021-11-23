TARGET = ./key.out
INCLUDE = Resourses
SRCS = program/main.c \
		program/radix.c\
		program/bubble.c

.PHONY: all build test clean

all: clean build

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(INCLUDE) -o $(TARGET) $(SRCS)

build: $(TARGET)

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)