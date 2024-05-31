CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = testing.c stringbuffer.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = teststrbuff

.PHONY: clean

all: $(TARGET)

test: $(TARGET)
	@echo "Testing $*...\n"
	./$(TARGET)
	@echo "\n\n"

valgrind: $(TARGET)
	@echo "Testing $*...\n"
	valgrind --error-exitcode=2 --leak-check=full ./$(TARGET)
	@echo "\n\n"

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
