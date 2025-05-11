# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g3
INCLUDES = -I..  # 包含上级目錄的頭文件
LDFLAGS = -lm

# 使用vpath自動查找主目錄的.c文件
vpath %.c ..

# 包含當前目錄和主目錄的chip源文件
SRCS = $(wildcard *.c) chip_a.c chip_b.c chip_c.c
OBJS = $(SRCS:.c=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# 通用編譯規則，自動處理主目錄的.c文件
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
