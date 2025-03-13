# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g3 -std=c11 -fsanitize=thread -O2 -DCHIP_A
INCLUDES = -I/home/firststop0907/queue
LDFLAGS = -lpthread

# List of source files
SRCS = $(wildcard *.c)
# List of object files (derived from source files)
OBJS = $(SRCS:.c=.o)
# Name of the final executable
EXEC = main

# Default target to build the executable
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -O0 -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(EXEC)

# PHONY targets to ensure `make` works correctly with these names
.PHONY: all clean