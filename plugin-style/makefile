# 1. 編譯器與參數設定
CC = gcc
# -I. 包含目前目錄，-I.. 包含上一層目錄（為了讓編譯器找到 ../chip_a.h）
CFLAGS = -Wall -Wextra -g3 -I. -I.. -D_POSIX_C_SOURCE=200809L
LDFLAGS = -lm

# 2. 定義檔案路徑
# 取得目前目錄下所有的 .c (main.c, chip_core.c, chip_a_adapter.c)
LOCAL_SRCS = $(wildcard *.c)
# 指定上一層目錄的檔案
PARENT_SRCS = ../chip_a.c

# 合併所有來源檔案
SRCS = $(LOCAL_SRCS) $(PARENT_SRCS)

# 3. 處理物件檔案 (Object Files)
# 這會把 ../chip_a.c 變成目前的 chip_a.o，避免把 .o 產生在上一層目錄
OBJS = $(notdir $(SRCS:.c=.o))

# 4. 執行檔名稱
EXEC = main

# 預設目標
all: $(EXEC)

# 連結階段
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# 5. 編譯規則
# 編譯當前目錄的 .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 編譯上一層目錄的 .c (專門處理 ../chip_a.c)
%.o: ../%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean